import Control.Arrow
main = do
  (run 1 >>> print) 2
  
run :: Integer -> Integer -> Integer 
run n 20 = n
run n a = run (quot (n*a) (gcd n a)) (a+1)
