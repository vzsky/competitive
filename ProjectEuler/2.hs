import Control.Arrow
main = do
  print (solver 1)

fibs :: [Integer]
fibs = 1 : 1 : zipWith (+) fibs (tail fibs)

solver :: Int -> Integer 
solver n 
  | (&&) (((!!) fibs n) <= 4000000) (mod ((!!) fibs n) 2 == 0) = (+) (fibs!!n) (solver (n+1))
  | (fibs!!n) <= 4000000 = solver (n+1)
  | otherwise = 0
