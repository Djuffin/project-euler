module Main where 

f :: Integer -> Integer
f x = x^x

main = do putStrLn $ show $ (sum $ map f [1..1000]) `mod` (f 10)
