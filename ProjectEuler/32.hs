import Data.List

pandigital :: String -> Bool
pandigital x = sort x == "123456789"

check :: Int -> Int -> Bool
check n a
  | mod n a == 0 = pandigital $ show n ++ show a ++ show (n `div` a)
  | otherwise = False

checkn :: Int -> Bool
checkn n = any (check n) [2..(ceiling r)]
  where r = sqrt (fromIntegral n)

main = print $ sum $ filter checkn [2..100000]