module Problem13 where
import System.IO
import Numeric

main :: IO ()
main = do
        inh <- openFile "input13.txt" ReadMode
        content <- hGetContents inh
        let contentLines = lines content
        let numbers = map read contentLines
        let sumOfAll = sum numbers
        let result = take 10 $ show sumOfAll
        putStrLn result


