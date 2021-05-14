import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as B
readInts = map (fromJust . fmap fst . B.readInt) . B.words <$> B.getLine

merge :: Ord a => [a] -> [a] -> [a]
merge [] arr = arr
merge arr [] = arr
merge xs ys 
  | head xs <= head ys = [head xs]++(merge (drop 1 xs) ys)
  | otherwise          = [head ys]++(merge xs (drop 1 ys))

mergesort :: Ord a => [a] -> [a]
mergesort [] = []
mergesort [a] = [a]
mergesort xs = merge (mergesort $ firsthalf xs) (mergesort $ secondhalf xs)
  where 
    firsthalf xs = take (div (length xs) 2) xs
    secondhalf xs = drop (div (length xs) 2) xs

printList :: Show a => [a] -> IO()
printList x = putStrLn $ concat $ intersperse " " $ map show x

main = do 
  [n] <- readInts
  a <- readInts
  printList $ mergesort a