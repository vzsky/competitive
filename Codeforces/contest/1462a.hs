import Control.Arrow
main = interact $ lines >>> drop 1 >>> caser >>> map (words >>> map read >>> solve >>> map show >>> unwords) >>> unlines

caser :: [String] -> [String]
caser [] = []
caser (e1:e2:xs) = e2 : caser xs

solve :: [Int] -> [Int]
solve [] = []
solve [a] = [a]
solve a = [head a] ++ [last a] ++ solve (tail (init a))