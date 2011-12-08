module Main where
import Data.Maybe
import Data.List
 

{--
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
--}

maxN = 1000000

primes :: [Int]
primes = sieve [2..]
 where
  sieve (p:xs) = p : (sieve $ filter (\x -> x `mod` p /= 0) xs)

primesUnderN = takeWhile (< 1000) primes

digits :: Int -> [Int]
digits 0 = []
digits n = (n `mod` 10) : digits (n `div` 10)

fromDigits :: [Int] -> Int
fromDigits ds = foldl (\sum d -> sum * 10 + d) 0 ds

allRotations :: [a] -> [[a]]
allRotations xs =  nextRotation : (allRotations nextRotation)
    where nextRotation = (last xs : init xs)

isPrime x = not $ any (\n -> (x /= n) && (x `mod` n == 0)) primesUnderN

isCircularPrime n = all isPrime (map fromDigits rotations)
    where rotations = take (length ds) (allRotations ds)
          ds = digits n

answer = length $ filter isCircularPrime [2..maxN]
--answer = takeWhile (< maxN) primes

main = do putStrLn $ show $ answer




