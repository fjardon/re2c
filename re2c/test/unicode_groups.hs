{-
 - Compile: ghc -O2 -W -Wall unicode_groups.hs
 -
 - This program is a test generator for re2c's
 - support of Unicode encodings. It generates two
 - kinds of tests:
 - 1) Multiple tests for Unicode categories
 -     (like uppercase letters, space modifiers,
 -     etc.). We cannot test all categories at
 -     once, because they overlap.
 - 2) Single test for Unicode blocks (like
 -     Basic Latin, Hangul, Arabian, etc.).
 -     These blocks do not overlap, so we can
 -     generate common scanner for them.
 -
 - All tests have the same structure: re2c
 - block for Unicode range is tested on
 - encoded bytestring, which contains all
 - Unicode runes from this range and ends
 - with another Unicode rune.
 -
 - In case of success, generated program runs
 - silently, otherwise it outputs error to
 - stdout in form "test 'XXX' failed".
 -}

import           Data.Bits                           (shiftR, (.&.))
import qualified Data.ByteString.Char8         as BS (ByteString, unpack)
import           Data.Char                           (ord, isAlpha)
import qualified Data.CharSet                  as CS (fromCharSet, toAscList, union, empty, complement)
import           Data.CharSet                  as CS (CharSet)
import           Data.CharSet.Unicode.Category       (Category(..), categories)
import           Data.CharSet.Unicode.Block          (Block(..), blocks)
import qualified Data.IntSet                   as IS (foldl')
import qualified Data.List                     as L  (foldl')
import qualified Data.Text                     as T  (Text, pack)
import qualified Data.Text.Encoding            as TE (encodeUtf16LE, encodeUtf8)
import           Text.Printf                         (printf)


show_int :: Int -> String
show_int c = case c of
    _ | c < 0xFF   -> printf "\\x%02x" c
    _ | c < 0xFFFF -> printf "\\u%04x" c
    _              -> printf "\\U%08x" c


show_halfbyte :: Int -> Char
show_halfbyte 0   = '0'
show_halfbyte 1   = '1'
show_halfbyte 2   = '2'
show_halfbyte 3   = '3'
show_halfbyte 4   = '4'
show_halfbyte 5   = '5'
show_halfbyte 6   = '6'
show_halfbyte 7   = '7'
show_halfbyte 8   = '8'
show_halfbyte 9   = '9'
show_halfbyte 0xA = 'A'
show_halfbyte 0xB = 'B'
show_halfbyte 0xC = 'C'
show_halfbyte 0xD = 'D'
show_halfbyte 0xE = 'E'
show_halfbyte 0xF = 'F'
show_halfbyte _   = undefined


show_char :: Char -> String
show_char c =
    let x = ord c
        b1 = x `shiftR` 4
        b2 = x .&. 0xF
    in  "\\x" ++ [show_halfbyte b1, show_halfbyte b2]


show_range :: (Int, Int) -> String
show_range (l, h) = concat
    [ show_int l
    , "-"
    , show_int h
    ]


take_range :: [(Int, Int)] -> Int -> [(Int, Int)]
take_range [] c = [(c, c)]
take_range ((l, h) : xs) c =
    if c == h + 1
        then (l, c) : xs
        else (c, c) : (l, h) : xs


group_charset :: CharSet -> [(Int, Int)]
group_charset cs =
    ( reverse
    . IS.foldl' take_range []
    . snd
    . CS.fromCharSet
    ) cs


show_charset :: String -> CharSet -> String
show_charset name cs =
    let ranges = group_charset cs
    in  concat
            [ "\t\t"
            , name
            , " = ["
            , concatMap show_range ranges
            , "];"
            ]


show_category :: String -> CharSet -> String
show_category cat cs = show_charset cat cs


show_block :: (String, CharSet) -> String
show_block (bl, cs) = show_charset bl cs


prettify :: String -> String
prettify = map (\ c -> if isAlpha c then c else '_')


outer :: CharSet -> Char
outer cs = head $ CS.toAscList $ CS.complement cs


encode :: (T.Text -> BS.ByteString) -> CharSet -> String
encode f cs =
    ( concatMap show_char
    . BS.unpack
    . f
    . T.pack
    ) (CS.toAscList cs ++ [outer cs])


gen_test_category :: Category -> IO ()
gen_test_category (Category _ name cs _) =
    let catname = prettify name
        file8   = "unicode_group_" ++ catname ++ ".8.re"
        file16  = "unicode_group_" ++ catname ++ ".x.re"
        bs8     = encode TE.encodeUtf8 cs
        bs16    = encode TE.encodeUtf16LE cs
        content ctype s = unlines
            [ "#include <stdio.h>"
            , "#define YYCTYPE " ++ ctype
            , "bool scan(const YYCTYPE * start, const YYCTYPE * const limit)"
            , "{"
            , "\t__attribute__((unused)) const YYCTYPE * YYMARKER; // silence compiler warnings when YYMARKER is not used"
            , "#\tdefine YYCURSOR start"
            , catname ++ ":"
            , "\t/*!re2c"
            , "\t\tre2c:yyfill:enable = 0;"
            , "\t\t" ++ show_category catname cs
            , "\t\t" ++ catname ++ " { goto " ++ catname ++ "; }"
            , "\t\t[^] { return YYCURSOR == limit; }"
            , "\t*/"
            , "}"
            , "static const char buffer_" ++ catname ++ " [] = \"" ++ s ++ "\";"
            , "int main ()"
            , "{"
            , let arg1 = "reinterpret_cast<const YYCTYPE *> (buffer_" ++ catname ++ ")"
                  arg2 = "reinterpret_cast<const YYCTYPE *> (buffer_" ++ catname ++ " + sizeof (buffer_" ++ catname ++ ") - 1)"
              in  "\tif (!scan (" ++ arg1 ++ ", " ++ arg2 ++ "))"
            , "\t\tprintf(\"test '" ++ catname ++ "' failed\\n\");"
            , "}"
            ]
    in  writeFile file8 (content "unsigned char" bs8) >>
        writeFile file16 (content "unsigned short" bs16)


gen_test_blocks :: IO ()
gen_test_blocks =
    let (blocknames, charsets) = unzip $ map (\ (Block name cs) -> (prettify name, cs)) blocks
        blocknames'            = blocknames ++ ["All"]
        charsets'              = charsets ++ [L.foldl' CS.union CS.empty charsets]
        content ctype encf     = unlines
            [ "#include <stdio.h>"
            , "#define YYCTYPE " ++ ctype
            , "enum Block"
            , "{"
            , unlines $ map (\ s -> "\t" ++ s ++ ",") blocknames'
            , "\tError"
            , "};"
            , "Block scan(const YYCTYPE * start, const YYCTYPE * const limit, Block blk)"
            , "{"
            , "\t__attribute__((unused)) const YYCTYPE * YYMARKER; // silence compiler warnings when YYMARKER is not used"
            , "#\tdefine YYCURSOR start"
            , "\tswitch (blk)"
            , "\t{"
            , unlines $ map (\ s -> "\t\tcase " ++ s ++ ": goto " ++ s ++ " ;") blocknames'
            , "\t\tdefault: return Error;"
            , "\t}"
            , "\t/*!re2c"
            , unlines $ map show_block $ zip blocknames' charsets'
            , "\t*/"
            , unlines $ map
                (\ s -> unlines
                    [ s ++ ":"
                    , "\t/*!re2c"
                    , "\t\tre2c:yyfill:enable = 0;"
                    , "\t\t" ++ s ++ " { goto " ++ s ++ "; }"
                    , "\t\t[^] { if (YYCURSOR == limit) return " ++ s ++ "; else return Error; }"
                    , "\t*/"
                    ]
                ) blocknames'
            , "}"
            , unlines $ map
                (\ (s, cs) -> "static const char buffer_" ++ s ++ " [] = \"" ++ encode encf cs ++ "\";"
                ) $ zip blocknames' charsets'
            , "int main()"
            , "{"
            , unlines $ map
                (\ s -> unlines
                    [ let arg1 = "reinterpret_cast<const YYCTYPE *> (buffer_" ++ s ++ ")"
                          arg2 = "reinterpret_cast<const YYCTYPE *> (buffer_" ++ s ++ " + sizeof(buffer_" ++ s ++ ") - 1)"
                      in  "\tif (scan (" ++ arg1 ++ ", " ++ arg2 ++ ", " ++ s ++ ") != "++ s ++ ")"
                    , "\t\tprintf (\"test '" ++ s ++ "' failed\\n\");"
                    ]
                ) blocknames'
            , "}"
            ]
    in  writeFile "unicode_blocks.8.re" (content "unsigned char" TE.encodeUtf8) >>
        writeFile "unicode_blocks.x.re" (content "unsigned short" TE.encodeUtf16LE)


main :: IO ()
main = do
    mapM_ gen_test_category categories
    gen_test_blocks