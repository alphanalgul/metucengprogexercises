# Generics

This is a simple Java project that demonstrates the use of **generics**.

The project creates a custom generic list class called `Generic_List<T>`. This class can store items of any data type, such as `String`, `Integer`, `Double`, or custom objects.

## Project Overview

The main purpose of this project is to show how generic classes work in Java.

Instead of writing separate list classes for different data types, generics allow one reusable class to work with many types.

For example:

```java
Generic_List<String> list = new Generic_List<>();
```

This creates a generic list that stores `String` values.

## Technologies Used

* Java
* Object-Oriented Programming
* Generics
* ArrayList
* Encapsulation

## Project Structure

```text
Generics/
├── Generic_List.java
├── Main.java
└── README.md
```

## Class Descriptions

### `Generic_List.java`

This class defines a custom generic list.

```java
public class Generic_List<T>
```

The `<T>` means that the class can work with any object type.

The class stores data using:

```java
private ArrayList<T> list = new ArrayList<T>();
```

Because the list uses the generic type `T`, the same class can store different types of data depending on how it is created.

### Methods in `Generic_List`

#### `addItem(T item)`

Adds a new item to the list.

```java
public void addItem(T item) {
    list.add(item);
}
```

#### `getItem(int index)`

Returns the item at the given index.

```java
public T getItem(int index) {
    return list.get(index);
}
```

#### `getList()`

Returns the full internal `ArrayList`.

```java
public ArrayList<T> getList() {
    return list;
}
```

#### `setList(ArrayList<T> list)`

Replaces the current list with another `ArrayList`.

```java
public void setList(ArrayList<T> list) {
    this.list = list;
}
```

### `Main.java`

The `Main` class tests the generic list.

It creates a `Generic_List<String>` object, adds two string values, and prints the first item.

```java
Generic_List<String> list = new Generic_List<>();

list.addItem("abc");
list.addItem("def");

System.out.printf("First item of the list: %s", list.getItem(0));
```

## Example Output

```text
First item of the list: abc
```

## Main Concept

### What Are Generics?

Generics allow classes and methods to work with different data types while still keeping type safety.

For example, this list only accepts `String` values:

```java
Generic_List<String> stringList = new Generic_List<>();
```

This list only accepts `Integer` values:

```java
Generic_List<Integer> integerList = new Generic_List<>();
```

Because of generics, Java can catch type errors at compile time.

## Why Generics Are Useful

Without generics, a list might store general `Object` values. This can require manual casting and may cause runtime errors.

With generics:

* Code becomes reusable
* Type safety improves
* Casting is reduced
* The same class can work with different object types
* Errors can be detected earlier during compilation

## OOP Concepts Used

### Generic Class

`Generic_List<T>` is a generic class. The type `T` is decided when an object is created.

```java
Generic_List<String> list = new Generic_List<>();
```

### Encapsulation

The internal `ArrayList<T>` is private.

```java
private ArrayList<T> list = new ArrayList<T>();
```

The list is accessed through methods such as `addItem()`, `getItem()`, `getList()`, and `setList()`.

### Code Reusability

The same class can be reused for many different data types.

Examples:

```java
Generic_List<String> names = new Generic_List<>();
Generic_List<Integer> numbers = new Generic_List<>();
Generic_List<Double> grades = new Generic_List<>();
```

## How to Run

### 1. Compile the Java files

```bash
javac *.java
```

### 2. Run the program

```bash
java Main
```
