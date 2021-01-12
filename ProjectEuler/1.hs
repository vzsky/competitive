import Control.Arrow
main = interact solver

solver :: String -> String
solver a = do 
  (filter (\x -> ((mod x 3) == 0 || (mod x 5) == 0)) >>> sum >>> show) [1..(read a)]