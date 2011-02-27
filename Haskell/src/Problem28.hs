module Main where

numbers = [1..]

diags = takeAndSkip numbers 1 4
        where
            takeAndSkip xs s 0 = takeAndSkip xs (s + 2) 4
            takeAndSkip (x:xs) s n = x : takeAndSkip (drop s xs) s (n - 1)

n = 1001
answer = sum $ take (n * 2 - 1) diags

main = do putStrLn $ show $ answer
