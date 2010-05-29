module Problem9 where
import Data.Maybe
import Data.List

{--
A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,
    a^2 + b^2 = c^2

For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
--}

abcSum = 1000
allPossible = [1..abcSum]
abcs = [ (a, b, 1000 - a - b) | a <- allPossible, b <- allPossible]

test (a, b, c) = a * a + b * b == c * c
mul (a, b, c) = a * b * c

answer = mul $ fromJust $ find test abcs

