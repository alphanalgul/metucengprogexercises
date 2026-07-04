# Salary Composite Aggregation

## Description

This project is a simple **composition and aggregation example** written in **C++**.

The program demonstrates the difference between storing an object directly inside another class and storing a pointer to an existing object.

The project uses three main classes:

* `Salary`
* `CompositeEmployee`
* `AggregateEmployee`

---

## Program Behavior

The program creates salary objects and employee objects.

Each salary contains:

* Base salary
* Bonus salary

The program then:

1. Creates `Salary` objects
2. Creates `AggregateEmployee` objects using existing salary objects
3. Prints the initial salaries
4. Changes the original salary objects
5. Prints the updated salaries again

This shows that aggregation uses an existing object through a pointer.

---

## Features

* Defines a `Salary` class
* Stores base salary
* Stores bonus salary
* Demonstrates aggregation with `AggregateEmployee`
* Demonstrates composition with `CompositeEmployee`
* Uses getter and setter functions
* Prints salary information
* Separates classes into header files

---

## Project Structure

```text
Salary CompositeAggregation/
├── salary.h
├── CompositeEmployee.h
├── AggregateEmployee.h
└── salarymain.cpp
```

---

## Salary Class

The `Salary` class stores two values:

```cpp
int base;
int bonus;
```

The class includes functions to:

* Set base salary
* Set bonus salary
* Get base salary
* Get bonus salary
* Print salary information

---

## Composition

Composition means one class directly owns another object.

In this project, `CompositeEmployee` contains a `Salary` object directly:

```cpp
Salary s;
```

This means the salary object belongs to the `CompositeEmployee` object.

When the employee object is created, its salary object is also created.

---

## Aggregation

Aggregation means one class uses an object that exists outside of it.

In this project, `AggregateEmployee` stores a pointer to a `Salary` object:

```cpp
Salary* salary;
```

This means the salary object is created separately and then given to the employee.

If the original salary object changes, the aggregate employee sees the updated salary.

---

## Example Code

```cpp
Salary s1(2000, 300);
Salary s2(2500, 400);

AggregateEmployee e1(&s1);
AggregateEmployee e2(&s2);

e1.printSalary();
e2.printSalary();

s1.setBase(3500);
s2.setBonus(600);

e1.printSalary();
e2.printSalary();
```

---

## Example Output

```text
Initial salaries:
Base = 2000
Bonus = 300
Base = 2500
Bonus = 400

After changes:
Base = 3500
Bonus = 300
Base = 2500
Bonus = 600
```

---

## How to Run

### Compile

```bash
g++ salarymain.cpp -o salary
```

### Run

On Linux/macOS:

```bash
./salary
```

On Windows PowerShell:

```bash
.\salary.exe
```

---
