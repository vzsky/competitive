import Control.Arrow
main = do
  (run 100 >>> print) 100
  
run :: Integer -> Integer -> Integer
run a b
  | (show >>> isPalindrome) (a*b) = (run (a+1) >>> max (a*b)) b
  | a == 1000 = run 100 (b+1)
  | b == 1000 = 0
  | otherwise = run (a+1) b

isPalindrome :: String -> Bool
isPalindrome str = str == reverse(str)