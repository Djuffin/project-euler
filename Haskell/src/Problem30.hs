module Main where

digits :: Int -> [Int]
digits 0 = []
digits n = (n `mod` 10) : digits (n `div` 10)

numbers = [2..10^7]

test n = n == (sum $ map (^5) $ digits n)

answer = sum $ filter test numbers

main = do putStrLn $ show $ answer
