# Time Constructors

This project demonstrates the use of constructors and member functions in C++ through a simple `Time` class.

The program creates time objects, initializes them with default and custom values, and prints their hour, minute, and second values to the terminal.

## Overview

The project contains a `Time` class that stores basic time information using three integer values:

* Hour
* Minute
* Second

The default constructor initializes a `Time` object with zero values. The `createTime()` function is used to assign custom time values after the object is created.

## Files

```text
Time.h
Time.cpp
timemain.cpp
```

## Class Structure

### Time

The `Time` class stores:

* `hour`
* `minute`
* `second`

Main responsibilities:

* Initialize time values using the default constructor
* Assign custom time values using `createTime()`
* Print time values using `printTime()`

## Concepts Demonstrated

* Classes and objects
* Header files and implementation files
* Constructors
* Member functions
* Encapsulation
* Object initialization
* Basic terminal output

## Compilation

Compile the program using `g++`:

```bash
g++ -std=c++11 -Wall -Wextra timemain.cpp Time.cpp -o time
```

## Running the Program

After compilation, run:

```bash
./time
```

On Windows PowerShell, run:

```bash
.\time.exe
```

## Example Behavior

The program first creates a `Time` object using the default constructor and prints the default values. Then it creates another `Time` object, assigns custom values using `createTime()`, and prints the updated values.

Example output:

```text
Hour: 0
Minute: 0
Second: 0
Hour: 18
Minute: 39
Second: 44
```
