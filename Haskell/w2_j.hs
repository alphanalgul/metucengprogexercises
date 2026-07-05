firstxl :: Int -> Int -> String
firstxl x y = take x (drop y ( cycle ['A'..'Z'] ) )