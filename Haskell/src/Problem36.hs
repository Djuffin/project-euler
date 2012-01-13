module Main where
import Data.Char
import Data.List
import Numeric
 

{--
The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)
--}

maxN = 1000000

isPalindromicAtBase base n = str == (reverse str)
    where str = showIntAtBase base intToDigit n ""

isPalindromic n = (isPalindromicAtBase 10 n) && (isPalindromicAtBase 2 n)


answer = sum $ filter isPalindromic [1..maxN]

main = do putStrLn $ show $ answer




