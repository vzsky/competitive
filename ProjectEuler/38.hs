import Data.List

pandigital :: String -> Bool
pandigital x = sort x == "123456789"

str :: Int -> Int -> String
str 2 a = (show a) ++ (show (a*2))
str n a = (str (n-1) a) ++ (show (a*n))

main = do 
  let all = [2..9] >>= \x -> filter (pandigital ) $ map (str x) [1..9999]
  print $ last $ sort all