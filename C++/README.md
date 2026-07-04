# C++ Programming Exercises

This folder contains C++ programming exercises and small projects completed as part of programming practice and coursework. The examples focus mainly on object-oriented programming concepts such as classes, constructors, destructors, inheritance, polymorphism, operator overloading, composition, aggregation, dynamic memory management, and copy control.

Each subfolder is an independent exercise or assignment. Some folders contain small demonstration programs, while others contain larger multi-file projects.

## Folder Overview

```text
C++
├── AbstractClass
├── Account Expanded Constructors
├── Address Constructors
├── Adress Copy Destructor Assignment Constructors
├── DiamondInheritance1
├── GalacticBattle
├── OperatorOverloading
├── Rectangle Constructor
├── Salary CompositeAggregation
├── ShoppingCenter
├── Simple Programs
├── Student Child Class
├── Student Constructors
└── Time Constructors
```

## Projects and Exercises

### `AbstractClass`

Demonstrates abstract classes and polymorphism using polygon-related classes.

Main concepts:

* Abstract base classes
* Pure virtual functions
* Inheritance
* Runtime polymorphism
* Base class pointers

### `Account Expanded Constructors`

Demonstrates constructors and member functions using an account-based class example.

Main concepts:

* Constructors
* Class design
* Data members
* Member functions
* Object initialization

### `Address Constructors`

Demonstrates constructor usage with an address class.

Main concepts:

* Constructors
* Header and implementation files
* Class encapsulation
* Character arrays / C-style strings
* Object initialization

### `Adress Copy Destructor Assignment Constructors`

Demonstrates the Rule of Three using an address-related class.

Main concepts:

* Copy constructor
* Destructor
* Assignment operator overloading
* Dynamic memory management
* Deep copying
* Manual memory handling

### `DiamondInheritance1`

Demonstrates multiple inheritance and the diamond inheritance problem.

Main concepts:

* Inheritance
* Multiple inheritance
* Diamond inheritance
* Constructor behavior in inheritance hierarchies

### `GalacticBattle`

A larger C++ exercise/project based on a battle simulation theme.

Main concepts:

* Multiple classes
* Inheritance
* Polymorphism
* Object interaction
* Project-level class organization

### `OperatorOverloading`

Demonstrates operator overloading in C++.

Main concepts:

* Operator overloading
* Custom class behavior
* Member functions
* Object comparison or arithmetic-style operations

### `Rectangle Constructor`

Demonstrates basic constructors using a rectangle class.

Main concepts:

* Constructors
* Classes and objects
* Data members
* Member functions
* Basic object initialization

### `Salary CompositeAggregation`

Demonstrates composition and aggregation using a salary-related example.

Main concepts:

* Composition
* Aggregation
* Object ownership
* Class relationships
* Dynamic memory management

### `ShoppingCenter`

A larger shopping centre management system implemented with multiple classes.

The project models a shopping centre that can contain restaurants and shops. Employees can be assigned to businesses, and the program provides menu options for adding businesses, listing businesses, searching employees, printing shop statistics, finding suitable restaurants, and displaying the largest business.

Main concepts:

* Classes and objects
* Inheritance
* Polymorphism
* Virtual destructors
* Dynamic memory allocation
* Deep copying
* Copy constructors
* Assignment operator overloading
* Fixed-size arrays
* C-style strings

### `Simple Programs`

Contains small independent programs that demonstrate individual object-oriented programming concepts.

Included examples:

* Aggregation
* Composition
* Diamond inheritance
* Virtual inheritance

Main concepts:

* Aggregation
* Composition
* Multiple inheritance
* Virtual inheritance
* Constructors and destructors
* Dynamic memory allocation

### `Student Child Class`

Demonstrates basic inheritance using a `Student` base class and an `UndergraduateStudent` derived class.

Main concepts:

* Base class and derived class relationship
* Public inheritance
* Function reuse from a parent class
* Constructors
* Character arrays / C-style strings

### `Student Constructors`

Demonstrates constructor usage through a simple `Student` class.

Main concepts:

* Constructors
* Classes and objects
* Header and implementation files
* Character arrays / C-style strings
* Safe string copying
* Object initialization

### `Time Constructors`

Demonstrates constructors and member functions through a simple `Time` class.

Main concepts:

* Constructors
* Classes and objects
* Encapsulation
* Member functions
* Basic terminal output

## Compilation

Most folders contain independent C++ programs. Compile each project from inside its own folder.

General format:

```bash
g++ -std=c++11 -Wall -Wextra main_file.cpp other_files.cpp -o program_name
```

Example:

```bash
g++ -std=c++11 -Wall -Wextra studentmain.cpp Student.cpp -o student
```

Run on Linux/macOS:

```bash
./student
```

Run on Windows PowerShell:

```bash
.\student.exe
```

## Important Compilation Note

Do not compile unrelated folders or unrelated `.cpp` files together.

Many exercises contain their own `main()` function. If multiple files with different `main()` functions are compiled together, the compiler will produce a multiple definition error for `main()`.

Compile each assignment separately from its own folder.

## Example Compile Commands

### Student Constructors

```bash
cd "Student Constructors"
g++ -std=c++11 -Wall -Wextra studentmain.cpp Student.cpp -o student
```

### Time Constructors

```bash
cd "Time Constructors"
g++ -std=c++11 -Wall -Wextra timemain.cpp Time.cpp -o time
```

### Student Child Class

```bash
cd "Student Child Class"
g++ -std=c++11 -Wall -Wextra studentchildmain.cpp studentchild.cpp -o studentchild
```

### ShoppingCenter

```bash
cd "ShoppingCenter"
g++ -std=c++11 -Wall -Wextra shoppingmain.cpp Business.cpp Employee.cpp Restaurant.cpp Shop.cpp ShoppingCentre.cpp -o shopping
```

### Simple Programs

Each file in this folder has its own `main()` function, so compile them separately.

```bash
cd "Simple Programs"
g++ -std=c++11 -Wall -Wextra aggregation.cpp -o aggregation
g++ -std=c++11 -Wall -Wextra composite.cpp -o composite
g++ -std=c++11 -Wall -Wextra diamondinheritance2.cpp -o diamondinheritance2
```
