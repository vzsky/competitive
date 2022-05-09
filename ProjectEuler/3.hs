import Control.Arrow
main = do
  (solver 2 >>> print) 600851475143

solver :: Integer -> Integer -> Integer 
solver a n
  | n == 1          = a
  | mod n a == 0    = solver a (quot n a)
  | otherwise       = solver (a+1) n
