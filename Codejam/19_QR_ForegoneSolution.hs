import Control.Arrow

main = interact scanner

scanner :: String -> String
scanner = lines >>> zip [0..] >>> drop 1 >>> map handleCase >>> unlines

handleCase :: (Int, String) -> String
handleCase (x, y) = "Case #" ++ (show x) ++ ": " ++ (solve y)

solve :: String -> String
solve x = findA x ++ " " ++ findB x

findA :: String -> String
findA "" = ""
findA (x:xs)
  | (x == '4') = "2" ++ findA xs
  | otherwise  = [x] ++ findA xs

findB :: String -> String
findB "" = ""
findB (x:xs)
  | (x == '4') = "2" ++ findB xs
  | otherwise  = "0" ++ findB xs