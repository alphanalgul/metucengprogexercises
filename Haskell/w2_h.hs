powerrecursive :: Int -> Int -> Int
powerecursive x 0 = 1
powerrecursive x n = product ( replicate n x ) 