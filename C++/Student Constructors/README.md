# Student Constructors

This project demonstrates the use of constructors in C++ through a simple `Student` class.

The program creates student objects, initializes them with default and custom values, and prints their information to the terminal.

## Overview

The project contains a `Student` class that stores basic student information such as name, surname, student number, birthdate, and CGPA.

The default constructor initializes a student object with placeholder values. The `createStudent()` function is used to assign custom information to a student object after it is created.

## Files

```text
Student.h
Student.cpp
studentmain.cpp
```

## Class Structure

### Student

The `Student` class stores:

* Name
* Surname
* Student number
* Birthdate
* CGPA

Main responsibilities:

* Initialize student information using the default constructor
* Assign custom student information using `createStudent()`
* Print student information using `printStudent()`

## Concepts Demonstrated

* Classes and objects
* Header files and implementation files
* Constructors
* Member functions
* Encapsulation
* Character arrays / C-style strings
* Basic object initialization
* Safe string copying with null termination

## Compilation

Compile the program using `g++`:

```bash
g++ -std=c++11 -Wall -Wextra studentmain.cpp Student.cpp -o student
```

## Running the Program

After compilation, run:

```bash
./student
```

On Windows PowerShell, run:

```bash
.\student.exe
```

## Example Behavior

The program first creates a student using the default constructor and prints the default values. Then it creates another student, assigns custom information using `createStudent()`, and prints the updated information.

Example output may include:

```text
Name: Not Provided
Surname: Not Provided
Student No: 0
Birth Date: Not Provided
CGPA: 0

Name: Ahmet
Surname: Yilmaz
Student No: 2584635
Birth Date: 14/11/2003
CGPA: 2.65
```
