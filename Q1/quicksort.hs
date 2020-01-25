import Data.List

toCommaSeparatedString :: [String] -> String
toCommaSeparatedString = intercalate " "

quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []  
quicksort (x:xs) =   
    let smallerSorted = quicksort [a | a <- xs, a <= x]  
        biggerSorted = quicksort [a | a <- xs, a > x]  
    in  smallerSorted ++ [x] ++ biggerSorted


-- main = interact $ toCommaSeparatedString $ map show $ quicksort $ map (read::String->Int) . tail . words
-- main = interact $ toCommaSeparatedString $ map show $ quicksort $ map read . tail . words
-- main = interact $ show . quicksort . map read. tail . words

main = do
    input <- getContents
    putStr $ toCommaSeparatedString $ map show $ quicksort $ map (read::String->Int) $ tail $ words input