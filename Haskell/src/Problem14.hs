module Problem14 where
import Data.Maybe
import Data.Array
import Data.List
 

{--
The following iterative sequence is defined for the set of positive integers:

n =  n/2 (n is even)
n =  3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13  40  20  10  5  16  8  4  2  1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. 
Although it has not been proved yet (Collatz Problem), 
it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
--}

next n = if n `mod` 2 == 0 
            then n `div` 2
            else 3 * n + 1 

maxN = 1000000

lengthTo1 n = memory ! n
        where memory = listArray (1, 2 * maxN) (0 : map f [2..maxN])
              f x = 1 + memory ! next x

answer = snd $ maximumBy comparator $ zip all $ map lengthTo1 all 
         where
            all = [2..1000000]
            comparator (_, a) (_, b) = compare a b

next2 n = if (n - 1) `mod` 3 == 0
            then [(n - 1) `div` 3, 2 * n]
            else [2 * n]

lens = array (1, maxN)


--main = do putStrLn $ show $ answer




