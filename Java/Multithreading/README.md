# Multithreading

This folder contains simple Java examples for practicing multithreading.

The main program demonstrates two common ways of creating threads in Java:

1. Extending the `Thread` class
2. Implementing the `Runnable` interface

It also shows how multiple threads can be started from the same program and how thread priorities can be assigned.

## Files

```text
Multithreading/
│
├── Multithreading.java
├── Synchronization.java
└── README.md
```

## Overview

The project contains a basic multithreading example where different arithmetic operations are executed by separate threads.

The operations are:

* Addition
* Subtraction
* Multiplication
* Division

Each operation is placed inside its own thread task.

## Main Concepts Practiced

This exercise demonstrates the following Java concepts:

* Multithreading
* Extending the `Thread` class
* Implementing the `Runnable` interface
* Overriding the `run()` method
* Creating `Thread` objects
* Starting threads with `start()`
* Assigning thread priorities
* Running multiple tasks at the same time

## `Multithreading.java`

This is the main runnable file in the folder.

It contains four thread tasks:

### `Addition`

The `Addition` class extends `Thread`.

It calculates:

```java
3 + 5
```

### `Subtraction`

The `Subtraction` class also extends `Thread`.

It calculates:

```java
3 - 5
```

### `Multiplication`

The `Multiplication` class implements `Runnable`.

It calculates:

```java
3 * 5
```

### `Division`

The `Division` class also implements `Runnable`.

It calculates:

```java
3 / 5
```

## Thread Creation Methods

### 1. Extending `Thread`

In this approach, a class directly extends the `Thread` class and overrides the `run()` method.

Example from the project:

```java
public static class Addition extends Thread {
    @Override
    public void run() {
        int result = 3 + 5;
        System.out.printf("\nAddition result is %d", result);
    }
}
```

### 2. Implementing `Runnable`

In this approach, a class implements the `Runnable` interface and overrides the `run()` method.

Example from the project:

```java
public static class Multiplication implements Runnable {
    @Override
    public void run() {
        int multiplication = 3 * 5;
        System.out.printf("\nThe multiplication result is %d", multiplication);
    }
}
```

This object is then passed into a `Thread` object:

```java
Thread t3 = new Thread(new Multiplication());
```

## Thread Priorities

The program also assigns different priorities to some threads:

```java
t1.setPriority(Thread.MIN_PRIORITY);
t2.setPriority(Thread.NORM_PRIORITY);
t3.setPriority(Thread.MAX_PRIORITY);
t4.setPriority(Thread.NORM_PRIORITY);
```

Thread priority gives a suggestion to the JVM about which thread may be preferred by the scheduler.

However, priority does not guarantee the exact execution order. The output order can be different each time the program runs.

## `Synchronization.java`

This file currently contains a simple class structure:

```java
public class Synchronization {
    private int content;
    private boolean available;
}
```

At the moment, it does not contain a runnable example or synchronized methods.

It can later be expanded to practice concepts such as:

* `synchronized` methods
* Shared resources
* Producer-consumer problems
* Thread communication
* Race condition prevention

## How to Run

Open a terminal inside the `Multithreading` folder.

Compile the Java files:

```bash
javac *.java
```

Run the main multithreading example:

```bash
java Multithreading
```

## Example Output

The output may look like this:

```text
Addition result is 8
Subtraction result is -2
The multiplication result is 15
The division result is 0.60
```

The order of the lines may change because the operations are executed by different threads.
