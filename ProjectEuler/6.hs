main = interact solver
solver :: String -> String
solver a = do
  let n = read a :: Int
  show ((sqr (sum [1..n])) - (sum (map sqr [1..n])))
    where sqr = (\x -> x*x)