module Main where
import Data.List

{--
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a  b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
--}

divisors n = filter (\x -> n `mod` x == 0) [1..n - 1]
sumOfdivisors = sum . divisors

isAmicable x = x == x2 && x /= x1
	where 
		x1 = sumOfdivisors x
		x2 = sumOfdivisors x1

allAmicableUnder n = filter isAmicable [2..n]

main = putStrLn $ show $ sum $ allAmicableUnder 10000
