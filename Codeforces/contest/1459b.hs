import Control.Arrow
main = interact $ read >>> solve >>> show

solve :: Int -> Int
solve n
  | ((mod n 2) == 0) = ((div n 2) + 1) * ((div n 2) + 1)
  | otherwise = 2 * ((div n 2) + 1) * ((div n 2) + 2)