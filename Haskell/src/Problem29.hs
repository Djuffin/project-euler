module Main where
import Data.List

nums = [a^b | a <- [2..100], b <- [2..100]]

main = do putStrLn $ show $ length $ nub nums
