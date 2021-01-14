import Control.Arrow
main = interact $ lines >>> drop 1 >>> map (length >>> show) >>> unlines