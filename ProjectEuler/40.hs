champ :: String
champ = concat $ map show [0..]

main = do 
  -- each digit is shown, not the product.
  print $ map (champ !!) [1, 10, 100, 1000, 10000, 100000, 1000000]