--Recursive Data Types with Tree
--Binary Tree definition
data Tree = EmptyTree | Node Integer Tree Tree deriving (Show, Eq, Ord)
insertElement x EmptyTree = Node x EmptyTree EmptyTree -- BASE CASE
insertElement x (Node a left right) =
 if x == a -- DO NOTHING
 then (Node x left right)
 else if x < a -- INSERT TO LEFT
 then (Node a (insertElement x left) right)
 else -- INSERT TO RIGHT
 Node a left (insertElement x right)

--Question 1
inserter :: [Integer] -> Tree
inserter [] = EmptyTree
-- (x:xs) Pattern Matching! x is the first element, xs is the rest of the list
inserter (x:xs) = insertElement x (inserter xs)
 
-- Question 2a
minOf :: Tree -> Integer
minOf EmptyTree = error "Tree is empty"  -- Handle the case where the tree is empty
minOf (Node x EmptyTree _) = x  -- If the left subtree is empty, this node is the minimum
minOf (Node _ left _) = minOf left  -- Otherwise, continue to search in the left subtree

-- Question 2b
maxOf :: Tree -> Integer
maxOf EmptyTree = error "Tree is empty"  -- Handle the case where the tree is empty
maxOf (Node x _ EmptyTree) = x  -- If the right subtree is empty, this node is the maximum
maxOf (Node _ _ right) = maxOf right  -- Otherwise, continue to search in the right subtree

--Question 3
isEmpty :: Tree -> Bool
isEmpty EmptyTree = True
isEmpty _ = False

--Question 4 
searchElement :: Integer -> Tree -> Bool
searchElement _ EmptyTree = False
searchElement x (Node a left right) =
  if x == a then True
  else if x < a then searchElement x left
  else searchElement x right