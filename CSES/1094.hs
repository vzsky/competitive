import Control.Arrow
import Data.Char
main = interact $ lines >>> drop 1 >>> map (words >>> map read >>> solve) >>> unlines

solve :: [Int] -> String
solve a = show $ change (drop 1 a) (head a) 

change :: [Int] -> Int -> Int
change [] b = 0
change a b = max (b - (head a)) 0 + change (drop 1 a) (max (head a) b)