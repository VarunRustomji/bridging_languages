import Data.List
import Data.Char
-- Convert to

replace ::String -> String -> String -> String
replace a b (s:ss)
  | null ss = [s]
  | [s] == a = b ++ replace a b ss
  | otherwise = [s] ++ replace a b ss

wordsTill     :: (Char -> Bool) -> (Char -> Char) -> String -> String -> String
wordsTill predicate transform (s:ss) sep
  | null ss = [s]
  | predicate s = sep ++ [transform(s)] ++ wordsTill predicate transform ss sep
  | otherwise = [s] ++ wordsTill predicate transform ss sep

translateText :: String -> String -> String
translateText option inp
  | option == "snake_case" = wordsTill isUpper toLower (replace "-" "_" inp) "_"
  | option == "kebab-case" = wordsTill isUpper toLower (replace "_" "-" inp) "-"
  | otherwise = "Bad input"

lowerFirst :: String -> String
lowerFirst (a:rest) = [toLower a] ++ rest

main = do input <- getContents
          putStr $ translateText "snake_case" $ lowerFirst input
