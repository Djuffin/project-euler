module Main where 

pow :: Integer -> Integer -> Integer
pow x y = pow2 x y 1
            where
              pow2 x 0 acc = acc
              pow2 x y acc = pow2 x (y - 1) (acc * x)

f :: Integer -> Integer
f x = pow x x



main = do putStrLn $ show $ (sum $ map f [1..1000]) `mod` (f 10)
