setUnion :: [Int] -> [Int] -> [Int]
setUnion xs ys = filter (`notElem` ys) xs ++ ys

setIntersection :: [Int] -> [Int] -> [Int]
setIntersection xs ys = filter (`elem` ys) xs

setDifference :: [Int] -> [Int] -> [Int]
setDifference xs ys = filter (`notElem` ys) xs

setRest :: [Int] -> [Int] -> [Int]
setRest xs ys = filter (`notElem` ys) xs ++ filter (`notElem` xs) ys