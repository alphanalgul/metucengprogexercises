distance :: (Int,Int) -> (Int,Int) -> Float
distance (x1,y1) (x2,y2) = sqrt ( fromIntegral ( (x2 - x1)^2 ) + fromIntegral ( (y2 - y1)^2) )