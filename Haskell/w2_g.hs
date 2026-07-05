natural :: Int -> [Int]
natural 0 = []
natural n = (n : natural(n-1))

reversenatural :: [Int] -> [Int]
reversenatural list = reverse (list)
