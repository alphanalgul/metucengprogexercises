fx :: Int -> Double
fx x =
  if x == 5 then 1 - fromIntegral (x)
  else if x == 10 then fromIntegral (x) / fromIntegral (x^2) 
  else fromIntegral (x)