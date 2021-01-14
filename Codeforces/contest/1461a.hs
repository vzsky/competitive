import Control.Arrow
import Data.Char
main = interact $ lines >>> drop 1 >>> map (words >>> map read >>> solve) >>> unlines

solve :: [Int] -> String
solve a = take (head a) s
  where s = map (\x -> chr(ord('a') + (mod x 3))) [0..]