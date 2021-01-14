import Control.Arrow
main = interact $ lines >>> drop 1 >>> map (read >>> solve) >>> unlines

solve :: Int -> String
solve n = (map ((\x -> if x==n then 1 else (x+1)) >>> show) >>> unwords) [1..n]