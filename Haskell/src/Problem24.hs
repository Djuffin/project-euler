module Main where
import Data.List

list = [0..9]
pers = sort $ permutations list

main = do putStrLn $ show $ pers !! 999999

