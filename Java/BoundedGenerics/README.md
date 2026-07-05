# Bounded Generics
This is a simple Java project that demonstrates the use of **bounded generics**.

The program defines generic methods that can find the minimum and maximum values in an array, but only for data types that implement the `Comparable` interface.

## Project Overview

The purpose of this project is to show how Java generics can be restricted using an upper bound.

In this project, the generic type `E` is bounded by `Comparable<E>`:

```java id="2pxx4a"
<E extends Comparable<E>>
```

This means that the generic methods can only be used with objects that can be compared with each other.

For example, the methods work with types such as:

* `Integer`
* `Double`
* `String`
* Other custom classes that implement `Comparable`

## Project Structure

```text id="lcd9cj"
BoundedGenerics/
├── Main.java
└── README.md
```

## Main Concept

### Bounded Generic Method

A bounded generic method limits the type of objects that can be passed to the method.

In this project, the methods are written like this:

```java id="p1waom"
public static <E extends Comparable<E>> E min(E[] list)
```

and:

```java id="dy56fv"
public static <E extends Comparable<E>> E max(E[] list)
```

The `extends Comparable<E>` part ensures that the elements can be compared using the `compareTo()` method.

## How the Program Works

The program has two generic methods:

### `min()`

Finds the smallest element in an array.

```java id="qmbvmv"
if (list[i].compareTo(min) < 0) {
    min = list[i];
}
```

If the current element is smaller than the current minimum value, it becomes the new minimum.

### `max()`

Finds the largest element in an array.

```java id="ijvr84"
if (list[i].compareTo(max) > 0) {
    max = list[i];
}
```

If the current element is greater than the current maximum value, it becomes the new maximum.

## Example Code

```java id="8j37e6"
Integer[] list = {1, 2, 3, 4, 5};

System.out.printf("\nThe minimum element in the list is: %d", min(list));
System.out.printf("\nThe maximum element in the list is: %d", max(list));
```

## Example Output

```text id="y7n1r3"
The minimum element in the list is: 1
The maximum element in the list is: 5
```

## Why `Comparable` Is Needed

The program needs to compare two elements to decide which one is smaller or larger.

For example:

```java id="fvz0ks"
list[i].compareTo(min)
```

This comparison is only possible if the object type implements the `Comparable` interface.

Without this bound:

```java id="xcz6rj"
<E extends Comparable<E>>
```

Java would not know whether the objects can be compared.

## OOP Concepts Used

### Generics

Generics allow the same method to work with different data types.

Instead of writing separate methods for `Integer`, `Double`, or `String`, one generic method can be reused.

### Bounded Type Parameters

The type parameter is restricted to comparable types.

```java id="twv0tf"
<E extends Comparable<E>>
```

This improves type safety and prevents invalid types from being passed to the method.

### Comparable Interface

The `Comparable` interface allows objects to be ordered using the `compareTo()` method.

The method returns:

* A negative value if the current object is smaller
* Zero if both objects are equal
* A positive value if the current object is greater

## How to Run

### 1. Compile the Java file

```bash id="r3dbf3"
javac Main.java
```

### 2. Run the program

```bash id="xmckb0"
java Main
```

## Important Note

In the current code, the second print statement may say `"minimum"` even though it prints the maximum value.

It can be corrected like this:

```java id="7fqj5q"
System.out.printf("\nThe maximum element in the list is: %d", max(list));
```

