module Main where
import Data.List

{--
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. 
For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?
--}

primes :: [Integer]
primes = sieve [2..]
 where
  sieve (p:xs) = p : (sieve $ filter (\x -> x `mod` p /= 0) xs)

isPrime :: Integer -> Bool
isPrime n = not $ any (\x -> n `mod` x == 0) $ takeWhile (< sqrt_n) primes
			where 
				sqrt_n = floor $ sqrt $ fromInteger n 

fromDigits :: [Integer] -> Integer
fromDigits ds = foldl (\sum d -> sum * 10 + d) 0 ds

all_permutations = concatMap permutations [[1..x] | x <- [3..9]]
pandigitals = map fromDigits all_permutations
prime_pandigitals = filter isPrime pandigitals

main = putStrLn $ show $ maximum  prime_pandigitals