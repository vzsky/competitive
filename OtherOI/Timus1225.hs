main = interact (show . solve . read)

solve :: Int -> Integer
solve n = 2*(fib n)

fib :: Int -> Integer
fib n = f !! n 
  where f = 0:1:zipWith(+) f (tail f)
