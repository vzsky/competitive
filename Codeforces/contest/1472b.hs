import Control.Arrow
main = interact $ lines >>> drop 1 >>> caser >>> unzip >>> snd >>> map (words >>> map read >>> solve) >>> unlines

caser :: [String] -> [(String, String)]
caser [a, b] = [(a, b)]
caser (a:b:cs) = [(a, b)] ++ caser cs

solve :: [Int] -> String
solve a = do
  let two = (filter (\x -> x == 2) >>> length) a
  let one = (filter (\x -> x == 1) >>> length) a
  if ((mod two 2) == 0 && (mod one 2) == 0) 
    then "YES"
  else if ((mod one 2) == 0 && one > 0) 
    then "YES"
  else "NO"