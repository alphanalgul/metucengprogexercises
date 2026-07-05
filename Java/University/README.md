# University

This folder contains a compiled Java console application for a simple university system.

The project appears to model a university structure using separate classes for people, students, instructors, and the main university program.

## Files

```text id="z1tb6r"
University/
│
├── Instructor.class
├── Person.class
├── Student.class
├── University.class
└── README.md
```

## Overview

The project is based on object-oriented programming concepts.

The main idea is to represent different people in a university system. A general `Person` class is used as the base structure, while `Student` and `Instructor` represent more specific types of people.

The `University` class is the main entry point of the program.

## Main Concepts Practiced

This exercise is useful for practicing the following Java concepts:

* Classes and objects
* Object-oriented programming
* Inheritance
* Encapsulation
* Class relationships
* Separate class design
* Console-based Java programs
* Compiled Java bytecode files

## Class Descriptions

### `Person`

`Person` represents the general structure of a person in the university system.

It is likely used as the parent class for more specific person types such as students and instructors.

### `Student`

`Student` represents a student in the university system.

This class likely stores student-related information and behavior.

### `Instructor`

`Instructor` represents an instructor in the university system.

This class likely stores instructor-related information and behavior.

### `University`

`University` is the main class of the program.

It is the class that should be executed to run the application.

## Important Note About Source Files

This folder currently contains `.class` files instead of `.java` source files.

`.class` files are compiled Java bytecode files. They can be executed by the Java Virtual Machine, but they are not the original editable source code.

Because of this, the program can be run, but the code cannot be easily edited or recompiled unless the original `.java` files are also added to the folder.

Recommended source files would be:

```text id="d66yug"
Instructor.java
Person.java
Student.java
University.java
```

## How to Run

Open a terminal inside the `University` folder.

Run the program with:

```bash id="efgnax"
java University
```

## How to Compile

Since the folder currently does not include `.java` source files, there is nothing to compile directly.

If the source files are added later, the project can be compiled with:

```bash id="d8t0n0"
javac *.java
```

Then it can be run with:

```bash id="1h6gq8"
java University
```
