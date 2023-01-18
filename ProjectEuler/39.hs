import Data.List

triples :: Int -> [Int]
triples p = [a | a <- peri, b <- takeWhile (<= (min a (p-a))) peri, (p-a-b)^2 == a^2 + b^2]
  where peri = [1..1000]

main = do 
  let p = [1..1000]
  let all = zip p $ map (length . triples) p
  print $ head $ sortBy (\x y -> compare (snd y) (snd x)) all 