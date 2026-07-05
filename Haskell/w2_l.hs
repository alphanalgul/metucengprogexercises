calculateGPA :: [Char] -> [Int] -> Float
calculateGPA charlist intlist = calculatetotalweight charlist intlist / fromIntegral (calculatetotalcredits intlist)

calculatetotalweight :: [Char] -> [Int] -> Float
calculatetotalweight grades credits = sum [ lettergradetoweight g * fromIntegral c | (g,c) <- zip grades credits]


lettergradetoweight :: Char -> Float
lettergradetoweight c = 
  if c == 'A' then 4.0
  else if c == 'B' then 3.0
  else if c == 'C' then 2.0
  else if c == 'D' then 1.0 
  else if c == 'F' then 0.0
  else 0.0
  
calculatetotalcredits :: [Int] -> Int
calculatetotalcredits list1 = sum (list1)