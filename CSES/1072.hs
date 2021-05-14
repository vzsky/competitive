import Control.Arrow
import Data.Char
main = interact $ lines >>> head >>> read >>> solve >>> map show >>> unlines

solve :: Integer -> [Integer]
solve 1 = [0]
solve a = solve (a-1) ++ [div ((a*a)*(a*a-1)) 2 - 4*(a-1)*(a-2)]

  