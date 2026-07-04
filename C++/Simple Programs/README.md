# Simple C++ Programs

This folder contains small C++ example programs written to demonstrate core object-oriented programming concepts. Each file is an independent program with its own `main()` function, so the files should be compiled separately.

## Contents

```text
aggregation.cpp
composite.cpp
diamondinheritance2.cpp
```

## Programs

### `aggregation.cpp`

Demonstrates **aggregation**.

In aggregation, one class stores pointers or references to objects that are created outside the class. The aggregate object uses these objects but does not fully own their lifetime.

This example contains:

* `Component`
* `Aggregate`

The `Aggregate` class stores pointers to two existing `Component` objects and prints their values.

### `composite.cpp`

Demonstrates **composition**.

In composition, one class creates and owns other objects. When the composite object is destroyed, the objects it owns should also be destroyed.

This example contains:

* `Component`
* `Composite`

The `Composite` class dynamically creates two `Component` objects in its constructor and deletes them in its destructor.

### `diamondinheritance2.cpp`

Demonstrates the **diamond inheritance problem** and the use of **virtual inheritance**.

This example contains:

* `Person`
* `Student`
* `Academic`
* `StudentAcademic`

`Student` and `Academic` both inherit virtually from `Person`. Then `StudentAcademic` inherits from both `Student` and `Academic`. Virtual inheritance ensures that only one shared `Person` base object exists inside a `StudentAcademic` object.

## Compilation

Since each file has its own `main()` function, compile each program separately.

### Compile `aggregation.cpp`

```bash
g++ -std=c++11 -Wall -Wextra aggregation.cpp -o aggregation
```

Run:

```bash
./aggregation
```

On Windows PowerShell:

```bash
.\aggregation.exe
```

### Compile `composite.cpp`

```bash
g++ -std=c++11 -Wall -Wextra composite.cpp -o composite
```

Run:

```bash
./composite
```

On Windows PowerShell:

```bash
.\composite.exe
```

### Compile `diamondinheritance2.cpp`

```bash
g++ -std=c++11 -Wall -Wextra diamondinheritance2.cpp -o diamondinheritance2
```

Run:

```bash
./diamondinheritance2
```

On Windows PowerShell:

```bash
.\diamondinheritance2.exe
```
