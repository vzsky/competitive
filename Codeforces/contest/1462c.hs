import Control.Arrow
main = interact $ lines >>> drop 1 >>> map (read >>> (solve 9)) >>> unlines

solve :: Int -> Int -> String
solve b a
  | (a > 45) = "-1"
  | (a <= b) = show a
  | otherwise = (solve (b-1) (a-b)) ++ (show b)