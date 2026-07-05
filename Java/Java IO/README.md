# Java IO

This folder contains a Java console application that demonstrates basic file input/output operations in Java.

The program manages a simple list of students and shows two different ways of saving student data into files:

1. Writing individual fields manually using `DataOutputStream`
2. Writing complete objects using Java serialization with `ObjectOutputStream`

## Overview

The application allows the user to:

* Add a student
* Print all saved students
* Save student data to files
* Read student data back from files when the program starts

Each student has:

* Student ID
* Student name
* Date of birth

The date of birth is entered in the following format:

```text
dd/MM/yyyy
```

Example:

```text
12/05/2003
```

## Files

```text
Java IO/
│
├── JavaIO.java
└── README.md
```

## Main Concepts Practiced

This exercise demonstrates the following Java concepts:

* File handling
* Binary file input/output
* Object serialization
* Object deserialization
* `ArrayList`
* `Scanner` input
* Exception handling
* `Serializable` interface
* `DataInputStream` and `DataOutputStream`
* `ObjectInputStream` and `ObjectOutputStream`
* Reading until end of file using `EOFException`

## How the Program Works

When the program starts, it checks whether the required data files exist. If they do not exist, the program creates them.

The program then loads existing student records from the non-serialized data file.

After that, the user is shown a simple menu:

```text
1. Add Student
2. Print Students
3. Exit
```

If the user adds a student, the student is added to the list and saved to both files.

If the user prints students, all currently stored students are displayed on the console.

## Data Files Created

When the program runs, it may create the following files:

```text
student_no_serial.dat
student.dat
```

### `student_no_serial.dat`

This file stores student data manually by writing each field one by one:

* ID
* Name
* Date of birth

This uses:

```java
DataOutputStream
DataInputStream
```

### `student.dat`

This file stores complete `Student` objects using serialization.

This uses:

```java
ObjectOutputStream
ObjectInputStream
```

## How to Run

Open a terminal inside this folder and compile the Java file:

```bash
javac JavaIO.java
```

Then run the program:

```bash
java JavaIO
```

## Example Usage

```text
1.Add Student

2.Print Students

3.Exit

Enter a choice:
1

Enter student ID:
1001

Enter the student name:
Ali Veli

Enter student date of birth:
12/05/2003
```

Printing students may produce output similar to:

```text
Student ID: 1001
Student Name: Ali Veli
Student Date of Birth: 2003-05-12
```
