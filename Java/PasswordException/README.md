# Password Exception

This folder contains a simple Java console program that demonstrates custom exception handling.

The program asks the user to enter a password and checks whether the password satisfies some basic validation rules. If the password is invalid, a custom exception is thrown and the user is asked to enter another password.

## Files

```text
PasswordException/
│
├── Password.java
├── PasswordException.java
└── README.md
```

## Overview

The project contains two main classes:

* `Password`
* `PasswordException`

The `Password` class handles password input and validation.

The `PasswordException` class is a custom exception class used when the entered password does not satisfy the required conditions.

## Main Concepts Practiced

This exercise demonstrates the following Java concepts:

* Classes and objects
* Constructors
* Encapsulation
* Getter and setter methods
* User input with `Scanner`
* Exception handling
* `try-catch` blocks
* Throwing exceptions with `throw`
* Custom exception classes
* String validation
* Regular expressions with `matches()`

## Password Rules

The entered password must satisfy all of the following rules:

1. The password must be at least 7 characters long.
2. The password must contain at least one letter.
3. The password must contain at least one number.

If any of these rules are not satisfied, the program throws a `PasswordException`.

## `Password.java`

This is the main class of the program.

It contains:

* A `password` field
* A default constructor
* A parameterized constructor
* `setPassword()` method
* `getPassword()` method
* `createPassword()` method
* `main()` method

The `createPassword()` method repeatedly asks the user to enter a password until a valid password is entered.

## `PasswordException.java`

This file defines a custom runtime exception.

```java
public class PasswordException extends RuntimeException {
    public PasswordException(String message) {
        super(message);
    }
}
```

This allows the program to display specific error messages when the password is invalid.

## How the Program Works

The program asks the user to enter a password:

```text
Enter a password:
```

Then it checks the password.

If the password is shorter than 7 characters, the program displays:

```text
Password is too short!
```

If the password does not contain any letters, the program displays:

```text
Password does not contain any letters!
```

If the password does not contain any numbers, the program displays:

```text
Password does not contain any numbers!
```

If the password is valid, the program records it and prints a success message.

## Example Usage

Invalid password example:

```text
Enter a password:
abc

Password is too short!
```

Another invalid password example:

```text
Enter a password:
abcdefg

Password does not contain any numbers!
```

Valid password example:

```text
Enter a password:
abc1234

Password Recorded. Your password is abc1234
```

## How to Run

Open a terminal inside the `PasswordException` folder.

Compile the Java files:

```bash
javac *.java
```

Run the program:

```bash
java Password
```
