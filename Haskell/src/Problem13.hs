module Problem13 where
import System.IO
import Numeric

--Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
main :: IO ()
main = do
        inh <- openFile "input13.txt" ReadMode
        content <- hGetContents inh
        let contentLines = lines content
        let numbers = map read contentLines
        let sumOfAll = sum numbers
        let result = take 10 $ show sumOfAll
        putStrLn result


