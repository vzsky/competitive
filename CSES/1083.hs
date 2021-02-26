import Control.Arrow
import Data.List
main = interact $ lines >>> drop 1 >>> map (sort . map read . words) >>> head >>> solve 1 >>> show
solve :: Int -> [Int] -> Int
solve x a 
  | a == []       = x
  | (head a) == x = solve (x+1) (tail a)
  | otherwise     = x