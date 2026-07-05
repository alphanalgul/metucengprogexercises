tuplemaxtwolist :: [Int] -> [Int] -> (Int,Int)
tuplemaxtwolist list1 list2 = (maximum list1 , maximum list2)

searchitem :: Int -> [Int] -> [Int]
searchitem x xs = if x `elem` xs then xs else x:xs

returnthird :: (a,a,a) -> a
returnthird (a,b,c) = c

distance :: (Int,Int) -> (Int,Int) -> Float
distance (x1,x2) (y1,y2) = sqrt ( ( fromIntegral x2-fromIntegral x1)^2 + (fromIntegral y2 - fromIntegral y1)^2 )

salary :: String -> Int -> Int -> Float
salary emp_class rt ot = 
                   if emp_class == "Class 1" then 10 * fromIntegral rt
				   else if emp_class == "Class 2" || emp_class == "Class 3" then 7 * fromIntegral rt + 1.5 * fromIntegral ot
				   else if emp_class == "Class 4" then 5 * fromIntegral rt + 2.0 * fromIntegral ot
				   else 0.0
				   
recursivecreatelist :: Int -> [Int]
recursivecreatelist 0 = []
recursivecreatelist x = x:[] ++ recursivecreatelist(x-1)   

power :: Int -> Int -> Int
power x 0 = 1
power x n = x * power x (n-1)

f :: Int -> Float
f x = 
  if x == 5 then fromIntegral (1 - x)
  else if x == 10 then  fromIntegral x / fromIntegral x^2
  else fromIntegral x
  
firstXl :: Int -> Int -> String
firstXl x n = take x ( drop n ( cycle ['A'..'Z'] ) )

vowelcount :: String -> Int
vowelcount str = length [x | x <- str , x `elem` ['a','e','i','o','u'] ]

convertlettergrade :: Char -> Float
convertlettergrade c =
  if c == 'A' then 4.0
  else if c == 'B' then 3.0
  else if c == 'C' then 2.0
  else if c == 'D' then 1.0
  else if c == 'F' then 0.0
  else 0.0 
  
convertlist :: [Char] -> [Float]
convertlist [] = []
convertlist (x:xs) = [convertlettergrade x] ++ convertlist xs

calculateweight :: [Char] -> [Int] -> [Float]
calculateweight [] [] = []
calculateweight (x:xs) (y:ys) = [convertlettergrade x * fromIntegral y] ++ calculateweight xs ys

calculategpa :: [Char] -> [Int] -> Float
calculategpa grades credits = sum (calculateweight grades credits) / fromIntegral (sum credits)