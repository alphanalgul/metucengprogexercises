--Question 1
repli :: [a] -> Int -> [a]
repli [] _ = []
repli (x:xs) n = replicate n x ++ repli xs n

--Question 2 
compress :: Eq a => [a] -> [a]
compress [] = []

--dropWhile is a built-in function that process a list and removes elements from the beginning of the list
--as long as predicate holds(i.e,as long as the elements satisfy the condition)
compress (x:xs) = x : compress (dropWhile (==x) xs)

--Question 3
--Question 3a (Question 1 with lambda abstraction)
repliLambda :: [a] -> Int -> [a]
--Lambda abstraction takes 2 inputs: xs, n. 
--concatMap is a higher-order function in Haskell. It maps a function over each element of the list and then concatenates the results into a single list.
repliLambda = \xs n -> concatMap (\x -> replicate n x) xs

--Question 3b (Question 2 with lambda abstraction)
compressLambda :: Eq a => [a] -> [a]

--foldr is a built-in higher-order function in Haskell. It recursively processes each element of the list, starting from the rightmost element.
--foldr takes a function (in this case, (\x acc -> ...)), an initial accumulator value (here []), and the list xs.

--(\x acc -> if null acc || x /= head acc then x : acc else acc)
--This function takes an element x and an accumulator acc. null acc checks if the accumulator list is empty (i.e., it's the first element being processed).
--x /= head acc checks if the current element x is different from the first element of the accumulator.
--If either of these conditions is true, it prepends x to the accumulator (x : acc), meaning x will be included in the result.
--If x is equal to the first element of the accumulator (i.e., it's a duplicate), it just returns acc unchanged.

compressLambda = \xs -> foldr (\x acc -> if null acc || x /= head acc then x : acc else acc) [] xs

--Question 4
--Question 4a (Recursive Approach)
countNumbersRecursive :: String -> Int
countNumbersRecursive [] = 0
countNumbersRecursive (x:xs) =
   if x `elem` ['0'..'9'] then 1 + countNumbersRecursive xs 
   else  countNumbersRecursive xs
   
--Question 4b (List Comperehension Approach)
countNumbersListComp :: String -> Int
countNumbersListComp xs = length ( [ x | x <- xs, x `elem` ['0'..'9'] ] )

--Question 5
--Floating a for float (/ float division, `div` integer division)
sumEquation :: Double -> Double
sumEquation j = sum [(i^2 + 6) / (2 * i + 1) | i <- [0..j] ]

--Question 6 Tracing sorusu sınava yakın coz

--Question 7
--Union
setUnion :: (Eq a) => [a] -> [a] -> [a]
setUnion xs ys = xs ++ filter (`notElem` xs)  ys

--Intersection
setIntersection :: (Eq a) => [a] -> [a] -> [a]
setIntersection xs ys = filter (`elem` ys) xs

--Difference 
setDifference :: (Eq a) => [a] -> [a] -> [a]
setDifference xs ys = filter (`notElem` ys) xs

--Set Rest (Union without Intersection)
setRest :: (Eq a) => [a] -> [a] -> [a]
setRest xs ys = filter (`notElem` ys) xs ++ filter (`notElem` xs) ys 