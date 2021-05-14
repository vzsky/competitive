import Control.Arrow
import Data.Char
main = interact $ lines >>> drop 1 >>> map ( words >>> map read >>> solve >>> show) >>> unlines

solve :: [Int] -> Int
solve [r, c] 
  | m == c && mod m 2 == 0 = (m-1)*(m-1)+r
  | m == r && mod m 2 == 0 = (m-1)*(m-1)+2*m-c
  | m == c && mod m 2 == 1 = (m-1)*(m-1)+2*m-r
  | m == r && mod m 2 == 1 = (m-1)*(m-1)+c
  where m = max r c 
  