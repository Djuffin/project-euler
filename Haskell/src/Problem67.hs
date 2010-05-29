module Problem67 where
import System.IO
import Numeric

{--
By starting at the top of the triangle below and moving to adjacent 
numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in input67.txt
This is a much more difficult version of Problem 18. 
--}

getPairs :: [Int] -> [(Int, Int)]
getPairs [] = []
getPairs (a:[]) = []
getPairs (a:b:xs) = (a, b) : (getPairs (b:xs))

getMax ((a, b), c) = max (a + c) (b + c)


getNextLine :: [Int] -> [Int] -> [Int]
getNextLine line costs = map getMax ways
            where
                ways = zip pairs costs
                pairs = getPairs line'
                line' = [0] ++ line ++ [0]

getLastLine lines = foldl getNextLine [] lines


answer input =  maximum $ getLastLine input

main :: IO ()
main = do
        inh <- openFile "input67.txt" ReadMode
        content <- hGetContents inh
        let contentLines = lines content
        let input = map (map read . words) contentLines :: [[Int]]
        putStrLn $ show $ answer input



