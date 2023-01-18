
ways :: Int -> [Int] -> Int
ways 0 _ = 1
ways n [] = 0
ways n coins 
  | (head coins) <= n = (ways (n-(head coins)) coins) + (ways n (tail coins))
  | otherwise = ways n (tail coins)

main = print $ ways 200 [200, 100, 50, 20, 10, 5, 2, 1]