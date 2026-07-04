# Student Child Class

This project demonstrates basic inheritance in C++ using a `Student` base class and an `UndergraduateStudent` derived class.

The program creates student objects, stores their information, and prints their details.

## Overview

The project contains a base class named `Student` and a child class named `UndergraduateStudent`.

The `Student` class stores general student information such as name, student number, and CGPA. The `UndergraduateStudent` class inherits from `Student` and adds undergraduate-specific information such as year.

## Files

```text
student.h
studentchild.cpp
studentchildmain.cpp
undergraduatestudent.h
```

## Class Structure

### Student

The `Student` class is the base class of the project.

It stores:

* Student name
* Student number
* CGPA

Main responsibilities:

* Initialize student information
* Set student information using `createStudent()`
* Print student information using `printStudent()`

### UndergraduateStudent

The `UndergraduateStudent` class is derived from `Student`.

It stores:

* Year of study

Main responsibilities:

* Reuse the data and functions of the `Student` class
* Add undergraduate-specific information
* Create an undergraduate student using `createUndergradStudent()`


## Compilation

Compile the program using `g++`:

```bash
g++ -std=c++11 -Wall -Wextra studentchildmain.cpp studentchild.cpp -o studentchild
```

## Running the Program

After compilation, run:

```bash
./studentchild
```

On Windows PowerShell, run:

```bash
.\studentchild.exe
```

## Example Behavior

The program creates student objects and prints their information.

Example output may include:

```text
Name: Not Provided
Student Number: 0
CGPA: 0

Name: Zekican Budin
Student Number: 1234
CGPA: 4

Name: Zekican Budindi
Student Number: 12345
CGPA: 3.8
Year: 4
```
