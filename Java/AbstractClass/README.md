# Abstract Class

This is a simple Java project that demonstrates the use of an **abstract class** in object-oriented programming.

The project defines a general abstract class called `GeometricObject`, then creates specific shape classes such as `Rectangle` and `Circle` that inherit from it and implement their own area calculation methods.

## Project Overview

The main purpose of this project is to show how abstract classes work in Java.

An abstract class can define methods that must be implemented by child classes. In this project, the abstract class `GeometricObject` contains an abstract method called `area()`. The `Rectangle` and `Circle` classes extend this abstract class and provide their own versions of the `area()` method.

## Project Structure

```text id="9e89hh"
AbstractClass/
├── Circle.java
├── GeometricObject.java
├── Main.java
├── Rectangle.java
└── README.md
```

## Class Descriptions

### `GeometricObject.java`

This is the abstract parent class of the project.

It contains the abstract method:

```java id="7sqw2a"
public abstract double area();
```

Since this method is abstract, any class that extends `GeometricObject` must implement its own `area()` method.

### `Rectangle.java`

The `Rectangle` class extends `GeometricObject`.

It has two fields:

* `length`
* `height`

The area of the rectangle is calculated using:

```java id="0k6pvc"
return length * height;
```

### `Circle.java`

The `Circle` class extends `GeometricObject`.

It has one field:

* `radius`

The area of the circle is calculated using:

```java id="inyzq6"
return 3.14 * radius * radius;
```

### `Main.java`

The `Main` class is used to test the program.

It creates:

* A `Rectangle` object with length `10` and height `5`
* A `Circle` object with radius `5`

Then it prints the calculated areas.

## OOP Concepts Used

### Abstract Class

`GeometricObject` is an abstract class. It provides a common structure for geometric shapes but does not fully define how the area should be calculated.

```java id="dpzohu"
public abstract class GeometricObject {
    public abstract double area();
}
```

### Inheritance

Both `Rectangle` and `Circle` inherit from `GeometricObject`.

```text id="sj89lm"
GeometricObject
├── Rectangle
└── Circle
```

### Method Overriding

Each child class overrides the `area()` method in its own way.

For example:

* `Rectangle` calculates area using `length * height`
* `Circle` calculates area using `3.14 * radius * radius`

### Encapsulation

The shape properties are stored as private fields and accessed through getter and setter methods.

Examples:

```java id="xb35kd"
private double radius;
private double length;
private double height;
```

## How to Run

### 1. Compile the Java files

```bash id="g9hapw"
javac *.java
```

### 2. Run the program

```bash id="dindfn"
java Main
```

## Example Output

```text id="ywxpye"
Area of the Rectangle: 50.00
Area of the Circle: 78.50
```

