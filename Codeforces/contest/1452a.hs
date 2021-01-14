import Control.Arrow
main = interact $ lines >>> drop 1 >>> map (words >>> map read >>> solve >>> show) >>> unlines

solve :: [Int] -> Int
solve [a, b]
  | (a > b)   = solve [b, a]
  | (a == b)  = 2*b
  | otherwise = 2*b - 1