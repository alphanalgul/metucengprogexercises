# Inheritance with Interfaces in Java

This is a simple Java project that demonstrates the use of **inheritance** and **interfaces** together in object-oriented programming.

The project models a basic `Person` and `Student` relationship. A `Student` inherits common properties from the `Person` class and also implements behavior from Java interfaces.

## Project Overview

The purpose of this project is to show how a class can inherit fields and methods from a parent class while also implementing required methods from interfaces.

In this project:

* `Person` is the parent class.
* `Student` is the child class.
* `PersonThings` is an interface for general person actions.
* `StudentThings` is an interface for student-specific actions.
* `Main` takes student information from the user and prints student details and behaviors.

This project is console-based. It does not use Swing or graphical user interfaces.

## Project Structure

```text id="5zfker"
InheritancewithInterfaces/
├── Main.java
├── Person.java
├── PersonThings.java
├── Student.java
├── StudentThings.java
└── README.md
```

## Class and Interface Descriptions

### `PersonThings.java`

This is a Java interface that defines general actions a person can perform.

```java id="l26g9v"
public interface PersonThings {
    void breathe();
    void walk();
    void eat();
    void drink();
}
```

Any class that implements this interface must provide these methods.

### `StudentThings.java`

This is another Java interface. It defines actions related to being a student.

```java id="x3f89a"
public interface StudentThings {
    void study();
    void fail();
    void pass();
}
```

Any class that implements this interface must define student-specific behaviors.

### `Person.java`

The `Person` class represents a general person.

It stores common information such as:

* Name
* Surname
* Age
* Date of birth

The class implements `PersonThings`, so it provides methods such as:

* `breathe()`
* `walk()`
* `eat()`
* `drink()`

### `Student.java`

The `Student` class extends `Person`.

```java id="bv0b1i"
public class Student extends Person implements PersonThings, StudentThings
```

This means the `Student` class:

* Inherits fields and methods from `Person`
* Implements general person behaviors
* Implements student-specific behaviors

The `Student` class adds:

* University
* CGPA

It also includes a `printDetails()` method to display student information.

### `Main.java`

The `Main` class runs the program.

It asks the user to enter:

* Student name
* Student surname
* Student age
* Student date of birth
* Student university
* Student CGPA

Then it creates a `Student` object and calls its methods.

## Java Interfaces Used

This project uses **Java interfaces**, not graphical interfaces.

An interface in Java defines method names that a class must implement.

For example, `StudentThings` says that a student should have these behaviors:

```java id="8xxi8t"
void study();
void fail();
void pass();
```

The `Student` class then provides the actual implementation of those methods.

## Inheritance Structure

```text id="v831c1"
Person
└── Student
```

`Student` inherits common person attributes from `Person`, such as name, surname, age, and date of birth.

## Interface Implementation Structure

```text id="psw5s3"
PersonThings
├── Person
└── Student

StudentThings
└── Student
```

`PersonThings` defines general actions.

`StudentThings` defines student-specific actions.

## OOP Concepts Used

### Inheritance

The `Student` class inherits from the `Person` class.

This allows `Student` to reuse common person fields and methods instead of rewriting them.

### Interfaces

The project uses interfaces to define required behaviors.

* `PersonThings` defines general person actions.
* `StudentThings` defines student actions.

### Method Overriding

The `Student` class overrides methods from the parent class and interfaces.

For example, `Student` provides its own versions of methods such as:

```java id="yezyqi"
breathe()
eat()
drink()
walk()
study()
fail()
pass()
```

### Encapsulation

The project uses fields with getter and setter methods.

For example:

```java id="v2eeos"
getName()
setName()
getAge()
setAge()
getCGPA()
setCGPA()
```

## How to Run

### 1. Compile the Java files

```bash id="h1ffra"
javac *.java
```

### 2. Run the program

```bash id="apio32"
java Main
```

## Example Input

```text id="02mptl"
Enter student name:
Alphan

Enter student surname:
Algül

Enter student age:
22

Enter student Date of Birth:
15/04/2002

Enter student university:
METU NCC

Enter student CGPA:
3.25
```

## Example Output

```text id="ymfpnk"
Student Name: Alphan
Student Surname: Algül
Student Age: 22
Student Date of Birth: 2002-04-15
Student University: METU NCC
Student CGPA: 3.25

Alphan is breathing
Alphan is eating
Alphan is drinking
Alphan is walking
Alphan is studying
Alphan is failing from a course
Alphan is passing a course
```

## Important Note About the Folder Name

The word **Interfaces** in the folder name refers to **Java interfaces**, not GUI screens.
This project does not contain:
* `JFrame`
* `JButton`
* `JPanel`
* Swing windows
