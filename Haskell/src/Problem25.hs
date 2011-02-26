module Main where

threshold = 10 ^ 999
answer = f 1 1 3
    where f a b n = let next = a + b in
                    if next > threshold 
                      then n
                      else f next a (n + 1)

main = do putStrLn $ show $ answer

                        

