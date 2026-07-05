iteminlist :: Int -> [Int] -> [Int]
iteminlist  x list1 =
  if x `elem` list1 then list1
  else x:list1