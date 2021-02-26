import Control.Arrow
main = interact $ read >>> solve >>> map show >>> unwords
solve :: Int -> [Int]
solve n
  | n == 1 = [1]
  | even n = [n] ++ solve (div n 2)
  | odd n  = [n] ++ solve ((n*3)+1)