-- 1 Jan 1900 -> Mon

isLeap :: Int -> Int -- year to int(bool)
isLeap a 
  | ((mod a 400) == 0) || (((mod a 4) == 0) && ((mod a 100) /= 0)) = 1
  | otherwise = 0

months :: Int -> [Int] 
months y = [31, 28+isLeap(y), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

main = do
  let allMonths = [1900..2000] >>= \x -> months x 
  let days = zipWith (+) allMonths (0:days)
  let daysinrange = init $ drop 12 days
  print $ length $ filter (==6) $ map (`mod` 7) daysinrange