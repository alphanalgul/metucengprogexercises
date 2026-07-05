sumwithoutfirstlast :: [Int] -> Int
sumwithoutfirstlast xs = sum ( init ( tail xs ) )