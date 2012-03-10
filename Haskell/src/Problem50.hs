module Main where
import Data.List

{--
The prime 41, can be written as the sum of six consecutive primes:

41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?
--}

primes :: [Int]
primes = 2 : sieve [3,5..]
 where
  sieve (p:xs) = p : (sieve $ filter (\x -> x `mod` p /= 0) xs)

maxN = 1000000
primesBelowN n = takeWhile (<= n) primes

isPrime :: Int -> Bool
isPrime n = not $ any (\x -> n `mod` x == 0) $ primesBelowN sqrt_n
            where 
                sqrt_n = ceiling $ sqrt $ fromIntegral n 


sumOfFirstPrimes n = sumOfFirstPrimes' $ primes
    where 
        sumOfFirstPrimes' primes = if s < maxN  then s : (sumOfFirstPrimes' $ tail primes) else []
                            where s = sum $ take n primes

possiblePrimes n = filter isPrime $ sumOfFirstPrimes n

x = last $ filter (not . null . snd) $ map (\x -> (x, possiblePrimes x)) [5..1000]

main = putStrLn $ show $ x