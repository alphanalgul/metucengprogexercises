# Prolog Programming Exercises

This folder contains Prolog programming exercises completed as part of my METU NCC Computer Engineering programming practice for CNG 242. The exercises focus on logic programming fundamentals such as facts, rules, predicates, recursion, arithmetic relations, comparisons, and simple knowledge-base queries.

## Contents

| File                                                       | Description                                                                                                                                       |
| ---------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------- |
| [`add.pl`](./add.pl)                                       | Implements an addition relation where `add(X, Y, Z)` is true when `X + Y = Z`. It can also solve for the missing value when two values are known. |
| [`subtract.pl`](./subtract.pl)                             | Implements a subtraction relation where `subtract(X, Y, Z)` is true when `X - Y = Z`.                                                             |
| [`multiply.pl`](./multiply.pl)                             | Implements a multiplication relation where `multiply(X, Y, Z)` is true when `X * Y = Z`.                                                          |
| [`divide.pl`](./divide.pl)                                 | Implements a division relation where `divide(X, Y, Z)` is true when `X / Y = Z`.                                                                  |
| [`equal.pl`](./equal.pl)                                   | Checks whether two given numbers are equal.                                                                                                       |
| [`greater.pl`](./greater.pl)                               | Checks whether the first number is greater than or equal to the second number.                                                                    |
| [`smaller.pl`](./smaller.pl)                               | Checks whether the first number is smaller than the second number.                                                                                |
| [`find_max.pl`](./find_max.pl)                             | Finds the maximum of two given numbers.                                                                                                           |
| [`power.pl`](./power.pl)                                   | Calculates `X` raised to the power of `Y` using Prolog arithmetic.                                                                                |
| [`power_recursive.pl`](./power_recursive.pl)               | Calculates powers recursively.                                                                                                                    |
| [`square_root.pl`](./square_root.pl)                       | Calculates the square root of a given number.                                                                                                     |
| [`nth_root.pl`](./nth_root.pl)                             | Calculates the nth root of a given number.                                                                                                        |
| [`factorial.pl`](./factorial.pl)                           | Computes the factorial of a number recursively.                                                                                                   |
| [`fibo.pl`](./fibo.pl)                                     | Computes the nth Fibonacci number recursively.                                                                                                    |
| [`lettergrade.pl`](./lettergrade.pl)                       | Converts a numeric grade into a letter-grade message.                                                                                             |
| [`string_compare.pl`](./string_compare.pl)                 | Compares two strings and returns whether they are equal.                                                                                          |
| [`atoms.pl`](./atoms.pl)                                   | Demonstrates atoms and a simple fact using `likes(alice, pizza)`.                                                                                 |
| [`student.pl`](./student.pl)                               | Defines lecture and student facts, then queries students enrolled in a given course.                                                              |
| [`employee.pl`](./employee.pl)                             | Defines employee facts and finds employees whose salary is greater than 28,000.                                                                   |
| [`department.pl`](./department.pl)                         | Defines employee and department facts, then finds the manager of the Deli department.                                                             |
| [`exercise2.pl`](./exercise2.pl)                           | Queries employees based on department number or salary condition.                                                                                 |
| [`prolog_final_predicate.pl`](./prolog_final_predicate.pl) | Contains final-style Prolog predicates, including a piecewise mathematical function and a recursive function.                                     |

## Topics Covered

* Prolog facts and rules
* Predicate definitions
* Logical queries
* Arithmetic operations
* Bidirectional-style arithmetic predicates
* Number comparison
* Conditional expressions
* Recursion
* Factorial and Fibonacci calculations
* String comparison
* Atoms
* Simple knowledge bases
* Student-course relationships
* Employee-department relationships
* Piecewise mathematical predicates

## How to Run

You can run the files using a Prolog interpreter such as SWI-Prolog.

Example:

```bash
swipl factorial.pl
```

Then query the predicate:

```prolog
factorial(5, Result).
```

Expected result:

```prolog
Result = 120.
```

Another example:

```bash
swipl fibo.pl
```

```prolog
fibonacci(6, Result).
```

Expected result:

```prolog
Result = 8.
```

## Example Queries

### Addition

```prolog
add(3, 4, Result).
```

Expected result:

```prolog
Result = 7.
```

You can also solve for a missing value:

```prolog
add(3, Y, 10).
```

Expected result:

```prolog
Y = 7.
```

### Factorial

```prolog
factorial(5, Result).
```

Expected result:

```prolog
Result = 120.
```

### Fibonacci

```prolog
fibonacci(7, Result).
```

Expected result:

```prolog
Result = 13.
```

### Letter Grade

```prolog
lettergrade(86, Result).
```

Expected result:

```prolog
Result = "You passed with a BA".
```

### Employee Query

```prolog
well_paid_emp(First, Last).
```

This returns employees whose salary is greater than 28,000.

### Department Query

```prolog
deli_manager(First, Last).
```

This returns the first and last name of the manager of the Deli department.

### Student Query

```prolog
students(Name, 9414).
```

This returns the students enrolled in course `9414`.

## Notes

These files are intended as small standalone exercises. They are not organized as one large Prolog application. Each file can be loaded separately and tested through Prolog queries.
