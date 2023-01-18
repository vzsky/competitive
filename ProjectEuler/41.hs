import Data.List

isPrime :: Int -> Int -> Bool
isPrime a n
  | a^2 > n      = True
  | mod n a == 0 = False
  | otherwise    = isPrime (a+1) n;


permute :: String -> [String]
permute "" = [""]
permute s = [ (x:xs) | x <- s, xs <- (permute (delete x s)) ]

main = do 
  let pandigits = [2..9] >>= \n -> permute $ map ((!! 0).show) [1..n]
  let d :: [Int] = map read pandigits
  print $ maximum $ filter (isPrime 2) $ d