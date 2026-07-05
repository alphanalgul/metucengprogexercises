# Java Programming Exercises

This folder contains Java programming exercises completed as part of METU NCC CNG programming practice for CNG 443 Introduction to Object-Oriented Programming Languages and Systems.

The exercises cover core Java topics such as object-oriented programming, inheritance, interfaces, abstract classes, generics, bounded generics, exception handling, file I/O, serialization, multithreading, and console-based application design.

## Overview

The `Java` folder is organized into separate small projects. Each folder focuses on a specific Java concept or combines multiple concepts in a larger practice program.

Most projects are simple console applications. Some folders contain larger study examples for midterm or final exam preparation.

## Folder Structure

```text
Java/
│
├── AbstractClass/
├── BoundedGenerics/
├── CampusBookStorewithInterface/
├── FinalStudies/
├── Generics/
├── InheritancewithInterfaces/
├── Java IO/
├── MidtermStudies/
├── Multithreading/
├── PasswordException/
├── Player/
├── University/
└── README.md
```

## Projects

| Folder                         | Main Topic                 | Description                                                                                                                                                                                            |
| ------------------------------ | -------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| `AbstractClass`                | Abstract classes           | Demonstrates abstract class usage through a geometric object example with shape classes such as `Circle` and `Rectangle`.                                                                              |
| `BoundedGenerics`              | Bounded generics           | Demonstrates generic methods with bounded type parameters using `Comparable`.                                                                                                                          |
| `CampusBookStorewithInterface` | OOP, interfaces, file I/O  | A larger bookstore management system that practices interfaces, class relationships, users, items, reservations, and file storage.                                                                     |
| `FinalStudies`                 | Final exam practice        | A study project for final exam preparation, including employee records, menus, file handling, and object serialization.                                                                                |
| `Generics`                     | Generic classes            | Demonstrates a custom generic list structure using a type parameter.                                                                                                                                   |
| `InheritancewithInterfaces`    | Inheritance and interfaces | Demonstrates inheritance and interface implementation using a `Person` and `Student` structure.                                                                                                        |
| `Java IO`                      | File input/output          | Demonstrates binary file writing, reading, and object serialization using student records.                                                                                                             |
| `MidtermStudies`               | Midterm exam practice      | A university system practice project using students, instructors, inheritance, interfaces, lists, and exceptions.                                                                                      |
| `Multithreading`               | Threads                    | Demonstrates Java threads using both `Thread` and `Runnable`.                                                                                                                                          |
| `PasswordException`            | Custom exceptions          | Demonstrates password validation using a custom exception class.                                                                                                                                       |
| `Player`                       | Object composition         | Demonstrates how a `Player` object can contain related `Country` and `Team` objects.                                                                                                                   |
| `University`                   | OOP practice               | A university-related Java project that includes both `.java` source files and `.class` compiled files for practicing object-oriented programming concepts such as inheritance and class relationships. |

## Main Concepts Practiced

This folder is useful for reviewing the following Java topics:

* Classes and objects
* Constructors
* Encapsulation
* Getter and setter methods
* Inheritance
* Interfaces
* Abstract classes
* Method overriding
* Object composition
* Generic classes
* Generic methods
* Bounded type parameters
* `ArrayList`
* `Scanner` input
* Exception handling
* Custom exceptions
* File input/output
* Binary files
* Object serialization
* Object deserialization
* Multithreading
* `Thread`
* `Runnable`
* Menu-based console applications
* Basic GUI-related Java code

## How to Run the Projects

Most folders can be compiled and run from inside their own directory.

Example:

```bash
cd Java/Player
javac *.java
java Main
```

Another example:

```bash
cd Java/PasswordException
javac *.java
java Password
```

Because many folders use the default Java package and may contain repeated class names such as `Main`, it is better to compile each project folder separately instead of compiling the entire `Java` folder at once.

## Common Run Commands

| Folder                         | Compile        | Run                    |
| ------------------------------ | -------------- | ---------------------- |
| `AbstractClass`                | `javac *.java` | `java Main`            |
| `BoundedGenerics`              | `javac *.java` | `java Main`            |
| `CampusBookStorewithInterface` | `javac *.java` | `java CampusBookStore` |
| `FinalStudies`                 | `javac *.java` | `java Final`           |
| `Generics`                     | `javac *.java` | `java Main`            |
| `InheritancewithInterfaces`    | `javac *.java` | `java Main`            |
| `Java IO`                      | `javac *.java` | `java JavaIO`          |
| `MidtermStudies`               | `javac *.java` | `java University`      |
| `Multithreading`               | `javac *.java` | `java Multithreading`  |
| `PasswordException`            | `javac *.java` | `java Password`        |
| `Player`                       | `javac *.java` | `java Main`            |
| `University`                   | `javac *.java` | `java University`      |

## Notes About the `University` Folder

The `University` folder contains both Java source files and compiled class files.

The `.java` files are the editable source code files:

```text
Instructor.java
Person.java
Student.java
University.java
```

The `.class` files are compiled Java bytecode files:

```text
Instructor.class
Person.class
Student.class
University.class
```

The `.class` files are generated when the source files are compiled with:

```bash
javac *.java
```

Since `.class` files can be regenerated from the `.java` files, the source files are the most important files for editing and understanding the program.

## Requirements

* Java JDK installed
* Terminal, command prompt, or a Java IDE

Recommended IDEs:

* IntelliJ IDEA
* Eclipse
* Visual Studio Code

