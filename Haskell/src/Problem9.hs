module Problem9 where
import Data.Maybe
import Data.List


abcSum = 1000
allPossible = [1..abcSum]
abcs = [ (a, b, 1000 - a - b) | a <- allPossible, b <- allPossible]

test (a, b, c) = a * a + b * b == c * c
mul (a, b, c) = a * b * c

answer = mul $ fromJust $ find test abcs

