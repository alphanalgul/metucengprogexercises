# Haskell Programming Exercises

This folder contains Haskell programming exercises completed as part of my METU NCC Computer Engineering programming practice for CNG 242 Programming Language Concepts. The exercises focus on functional programming fundamentals such as recursion, pattern matching, guards, case expressions, list processing, custom data types, type classes, and tree structures.

## Contents

| File                                                               | Description                                                                                                                                                                     |
| ------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [`w1_a.hs`](./w1_a.hs)                                             | Sums the middle elements of a list by removing the first and last elements.                                                                                                     |
| [`w1_b.hs`](./w1_b.hs)                                             | Returns the body of a list without the first and last elements.                                                                                                                 |
| [`w1_c.hs`](./w1_c.hs)                                             | Finds the maximum value across two lists.                                                                                                                                       |
| [`w2.hs`](./w2.hs)                                                 | Collection of Week 2 exercises covering tuples, searching, distance calculation, salary calculation, recursion, powers, strings, vowels, grade conversion, and GPA calculation. |
| [`w2_b.hs`](./w2_b.hs)                                             | Returns the maximum elements of two lists as a tuple.                                                                                                                           |
| [`w2_c.hs`](./w2_c.hs)                                             | Adds an item to a list only if it is not already present.                                                                                                                       |
| [`w2_d.hs`](./w2_d.hs)                                             | Returns the third element of a tuple.                                                                                                                                           |
| [`w2_e.hs`](./w2_e.hs)                                             | Calculates the distance between two 2D points.                                                                                                                                  |
| [`w2_f.hs`](./w2_f.hs)                                             | Calculates salary based on employee class, regular time, and overtime.                                                                                                          |
| [`w2_g.hs`](./w2_g.hs)                                             | Creates a list of natural numbers recursively and reverses it.                                                                                                                  |
| [`w2_h.hs`](./w2_h.hs)                                             | Implements a recursive power-style function.                                                                                                                                    |
| [`w2_i.hs`](./w2_i.hs)                                             | Implements a conditional mathematical function.                                                                                                                                 |
| [`w2_j.hs`](./w2_j.hs)                                             | Generates a substring from a repeated alphabet sequence.                                                                                                                        |
| [`w2_k.hs`](./w2_k.hs)                                             | Counts vowels in a string using list comprehension.                                                                                                                             |
| [`w2_l.hs`](./w2_l.hs)                                             | Calculates GPA from letter grades and course credits.                                                                                                                           |
| [`catordog_where.hs`](./catordog_where.hs)                         | Demonstrates `where` clauses with a simple animal classification example.                                                                                                       |
| [`checknumber_caseexpression.hs`](./checknumber_caseexpression.hs) | Uses a case expression to classify a number as positive, negative, or zero.                                                                                                     |
| [`gradeletter_guard.hs`](./gradeletter_guard.hs)                   | Uses guards to convert numeric grades into letter-grade messages.                                                                                                               |
| [`countnumbersrecursive.hs`](./countnumbersrecursive.hs)           | Counts digit characters in a string.                                                                                                                                            |
| [`reverselist.hs`](./reverselist.hs)                               | Recursively reverses a list.                                                                                                                                                    |
| [`quicksort.hs`](./quicksort.hs)                                   | Implements quicksort using recursion and list comprehensions.                                                                                                                   |
| [`setoperations.hs`](./setoperations.hs)                           | Implements basic set operations such as union, intersection, difference, and symmetric difference.                                                                              |
| [`haskellweek4.hs`](./haskellweek4.hs)                             | Implements binary search tree operations such as insertion, minimum, maximum, emptiness check, and searching.                                                                   |
| [`haskellweek5.hs`](./haskellweek5.hs)                             | Covers list replication, duplicate compression, lambda expressions, folds, digit counting, summation, and set operations.                                                       |
| [`Eq.hs`](./Eq.hs)                                                 | Demonstrates creating an `Eq` instance for a custom `Person` data type.                                                                                                         |
| [`Ord.hs`](./Ord.hs)                                               | Demonstrates creating `Eq` and `Ord` instances for a custom `Person` data type.                                                                                                 |
| [`q1.hs`](./q1.hs)                                                 | Defines 3D shapes using algebraic data types and calculates area and volume.                                                                                                    |
| [`q2.hs`](./q2.hs)                                                 | Extends the 3D shape example using polymorphic numeric types.                                                                                                                   |
| [`TernaryTree.hs`](./TernaryTree.hs)                               | Implements a ternary tree with functions for creating a complete ternary tree, calculating height, and grouping/counting nodes by number of children.                           |

## Topics Covered

* Basic list operations
* Recursion
* Pattern matching
* Guards
* Case expressions
* `where` clauses
* List comprehensions
* Lambda expressions
* Higher-order functions such as `foldr` and `concatMap`
* Tuples
* String processing
* Custom algebraic data types
* Type classes such as `Eq` and `Ord`
* Binary search trees
* Ternary trees
* Set operations
* Simple mathematical and academic utility functions

## How to Run

Most files are written as small standalone Haskell exercises without a `main` function. They can be loaded and tested in GHCi.

Example:

```bash
ghci quicksort.hs
```

Then call the function inside GHCi:

```haskell
quicksort [5, 3, 8, 1, 2]
```

Example output:

```haskell
[1,2,3,5,8]
```

Another example:

```bash
ghci reverselist.hs
```

```haskell
reverselist [1,2,3,4]
```

Output:

```haskell
[4,3,2,1]
```

## Example Exercises

### Quicksort

```haskell
quicksort [7, 2, 9, 1, 5]
```

Output:

```haskell
[1,2,5,7,9]
```

### Set Operations

```haskell
setUnion [1,2,3] [3,4,5]
setIntersection [1,2,3] [2,3,4]
setDifference [1,2,3] [2]
setRest [1,2,3] [3,4]
```

### GPA Calculation

```haskell
calculateGPA ['A','B','C'] [3,4,3]
```

### Binary Search Tree

```haskell
let tree = inserter [5,3,7,2,4]
searchElement 4 tree
minOf tree
maxOf tree
```

### Ternary Tree

```haskell
let tree = completeternary 10
completeternaryheight tree
childnoternary tree
childlistternary tree
```

## Notes

These files are intended mainly for learning and practice. They are not structured as a single Haskell project with Cabal or Stack. Each file can be loaded separately in GHCi for testing and experimentation.
