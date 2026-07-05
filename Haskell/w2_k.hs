vowelcount :: String -> Int
vowelcount s = length ( [ x | x <- s , x `elem` ['a','e','i','o','u'] ] )