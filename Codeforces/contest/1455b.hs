import Control.Arrow
main = interact $ lines >>> drop 1 >>> map (read >>> solve) >>> unlines
 
solve :: Int -> String
solve b = do
  let a = b+1
  let ceilSqrt = fromIntegral >>> sqrt >>> ceiling
  let res = div (ceilSqrt (1 + (8*a))) 2
  let isSquare n = (((ceilSqrt n) * (ceilSqrt n)) == n)
  if isSquare (1 + (8*a)) 
    then show (res + 1)
  else if isSquare (1 + (8*(a-1)))
    then show (res - 1)
  else 
    show (res)