# Midterm Studies

This folder contains a Java console application created for practicing important object-oriented programming concepts before the midterm exam.

The project models a simple university system with students and instructors. It allows the user to add, delete, and print students and instructors through a menu-based console interface.

## Overview

The program includes:

* A base abstract `Person` class
* `Student` and `Instructor` classes that inherit from `Person`
* A `PersonThings` interface
* A custom `StudentError` exception class
* A `University` class that runs the main menu system

The main goal of this exercise is to practice Java inheritance, abstraction, interfaces, exception handling, arrays/lists, and user input.

## Files

```text
MidtermStudies/
│
├── Person.java
├── Student.java
├── Instructor.java
├── PersonThings.java
├── StudentError.java
├── University.java
└── README.md
```

## Main Concepts Practiced

This project demonstrates the following Java concepts:

* Classes and objects
* Abstract classes
* Inheritance
* Interfaces
* Method overriding
* Constructors
* Encapsulation
* Getters and setters
* `ArrayList`
* `Scanner` input
* Exception handling
* Custom exceptions
* Date parsing with `SimpleDateFormat`
* Menu-based console programming
* Basic generic methods

## Class Descriptions

### `Person`

`Person` is an abstract base class for people in the university system.

It stores common information such as:

* Name
* Surname
* ID
* Registration date
* Birthdate

It also contains an abstract method:

```java
public abstract void printDetails();
```

This method is implemented differently by the `Student` and `Instructor` classes.

### `Student`

`Student` extends the `Person` class and implements the `PersonThings` interface.

A student has:

* Name
* Surname
* ID
* Registration date
* Birthdate
* Taken courses
* Advisor

The class includes a `printDetails()` method that prints the student's information and courses.

### `Instructor`

`Instructor` also extends the `Person` class and implements the `PersonThings` interface.

An instructor has:

* Name
* Surname
* ID
* Registration date
* Birthdate
* Salary
* Taught courses

The class includes a `printDetails()` method that prints the instructor's information, salary, and courses.

### `PersonThings`

`PersonThings` is an interface that defines common actions for a person:

```java
Eat();
Breathe();
Drink();
Walk();
```

Both `Student` and `Instructor` implement this interface.

### `StudentError`

`StudentError` is a custom runtime exception class.

It is used to represent student-related errors, such as invalid input or a student not being found.

### `University`

`University` contains the main method of the program.

It manages two lists:

* Student list
* Instructor list

It also provides the console menu that allows the user to interact with the system.

## Program Menu

When the program runs, the user can choose from the following options:

```text
1. Add a Student
2. Delete a Student
3. Add Courses for a Student
4. Print all student details
5. Add an Instructor
6. Delete an Instructor
7. Add Courses for an instructor
8. Print all instructor details
9. Calculate total instructor salary
10. Exit
```

## Features

The program allows the user to:

* Add new students
* Delete students by ID
* Add courses to a student
* Print all student details
* Add new instructors
* Delete instructors by ID
* Add courses taught by an instructor
* Print all instructor details
* Calculate the total salary of all instructors
* Exit the system

## How to Run

Open a terminal inside the `MidtermStudies` folder.

Compile the Java files:

```bash
javac *.java
```

Run the program:

```bash
java University
```

## Example Usage

```text
Welcome to the University system!

1. Add a Student
2. Delete a Student
3. Add Courses for a Student
4. Print all student details
5. Add an Instructor
6. Delete an Instructor
7. Add Courses for an instructor
8. Print all instructor details
9. Calculate total instructor salary
10. Exit

Enter your choice:
```

Example student input:

```text
Enter the student name:
Ali

Enter the student surname:
Veli

Enter student id:
1001

Enter student birthday:
12/05/2003
```
design.

