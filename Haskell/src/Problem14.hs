module Main where
import Data.Maybe
import Data.Array
import Data.List

import Control.Parallel
import Control.Parallel.Strategies
import Control.Monad.State
import System.IO.Unsafe

import qualified Data.Map as Map
 

{--
The following iterative sequence is defined for the set of positive integers:

n =  n/2 (n is even)
n =  3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13  40  20  10  5  16  8  4  2  1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. 
Although it has not been proved yet (Collatz Problem), 
it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
--}

next n = if n `mod` 2 == 0 
            then n `div` 2
            else 3 * n + 1 

data CalcState = CalcState {
                    numbers :: [Integer],
                    results :: Map.Map Integer Int
                  }



isDone :: State CalcState Bool          
isDone = do state <- get
            return $ null $ numbers state

lookInResults :: Integer -> State CalcState (Maybe Int)
lookInResults n = do state <- get
                     return $ Map.lookup n (results state)

calcNext2 :: State CalcState ()
calcNext2 = do state <- get
               let n = head (numbers state)
               let nextN = next n
               cachedNextResult <- lookInResults nextN
               case cachedNextResult of
                    (Just x) -> do let newNumbers = tail (numbers state)
                                   let newResults = Map.insert n (x `seq` x + 1) (results state)
                                   let newState = CalcState newNumbers newResults 
                                   put newState
                    Nothing -> do let newNumbers = nextN : (numbers state)
                                  let newState = state { numbers = newNumbers}
                                  put newState

calcNext :: State CalcState ()
calcNext = do state <- get
              let n = head (numbers state)
              --let c = unsafePerformIO (printX n n)
              cachedResult <- lookInResults n
              case cachedResult of
                (Just x) -> do let newNumbers = tail (numbers state)
                               let newState = state { numbers = newNumbers}
                               put newState
                              
                Nothing  -> calcNext2

                                                
calcAll :: State CalcState (Map.Map Integer Int)
calcAll = do done <- isDone 
             if not done then calcNext >> calcAll
                         else do state <- get
                                 return $ results state

printX :: Integer -> Integer -> IO Integer
printX x r = do putStrLn $ show x
                return r

maxN = 1000000 
initialState = CalcState { numbers = [1..maxN], results = Map.insert 1 0 Map.empty }

        
answer = maximumBy comparator $ Map.toList memory  
          where
            memory = evalState calcAll initialState
            comparator (_, a) (_, b) = compare a b


main = do putStrLn $ show $ answer




