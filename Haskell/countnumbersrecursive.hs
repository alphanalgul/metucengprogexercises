countnumbersrecursive :: [Char] -> Int
countnumbersrecursive xs = length ([ x | x <- xs ,  x `elem` ['0'..'9'] ])