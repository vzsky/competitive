import Control.Arrow
import Data.Char
main = interact $ lines >>> head >>> words >>> head >>> read >>> solve

solve :: Int -> String
solve a 
  | a == 3 = "NO SOLUTION"
  | a == 2 = "NO SOLUTION"
  | otherwise = (perm 2 >>> map show >>> unwords) a

perm :: Int -> Int -> [Int] 
perm b a 
  | a == 1 = [1]
  | b <= a = [b] ++ perm (b+2) a
  | mod b 2 == 0 = perm 1 a
  | otherwise = []