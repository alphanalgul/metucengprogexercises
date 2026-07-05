reverselist :: [Int] -> [Int]
reverselist [] = []
reverselist (x:xs) = (reverselist xs) ++ [x]