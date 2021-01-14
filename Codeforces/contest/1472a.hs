import Control.Arrow
main = interact $ lines >>> drop 1 >>> map (words >>> map read >>> solve) >>> unlines

solve :: [Int] -> String
solve [w, h, n]
  | ((two (w*h)) >= n) = "YES"
  | otherwise = "NO"

two :: Int -> Int
two x
  | (mod x 2 == 0) = 2 * two (div x 2)
  | otherwise = 1