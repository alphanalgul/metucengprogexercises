# Shopping Centre Management System

This project implements a **Shopping Centre Management System** in C++ using object-oriented programming principles. The program models a shopping centre that can contain different types of businesses, such as restaurants and shops, and allows employees to be assigned to these businesses.

## Overview

The system is menu-driven and runs in the terminal. A user can add businesses, add employees to existing businesses, list businesses, search employees, filter shops by type, find suitable restaurants by seat capacity, and display the largest business in the shopping centre.

The project is implemented without using `std::string` or STL containers. Instead, it uses dynamically allocated C-style strings and fixed-size arrays, following constraints.

## Features

* Add a new business to the shopping centre
* Add employees to a selected business
* Print all businesses
* Print businesses with their employees
* Print shop statistics by shop category
* List shops by selected type
* Find restaurants suitable for a required number of seats
* Search employees by name
* Print the largest business or businesses
* Support deep copying through copy constructors and assignment operators

## Class Structure

### Employee

Represents an employee working in a business.

Stores:

* First name
* Last name
* SSN

Main responsibilities:

* Set and get employee information
* Print employee details
* Check whether an employee name contains a search keyword

### Business

Base class for all business types.

Stores:

* Business name
* Business size
* Employee list
* Employee count
* Business type identifier

Main responsibilities:

* Manage business name and size
* Add employees
* Print business information
* Print employees
* Search employees by name

### Shop

Derived from `Business`.

Represents a shop in the shopping centre.

Supported shop types:

* Clothing
* Technology
* Accessories
* Beauty

Main responsibilities:

* Store and manage shop type
* Print shop-specific business information
* Override business printing behavior

### Restaurant

Derived from `Business`.

Represents a restaurant in the shopping centre.

Stores:

* Number of seats

Main responsibilities:

* Store and manage seating capacity
* Check whether the restaurant is suitable for a requested number of seats
* Print restaurant-specific business information

### ShoppingCentre

Represents the shopping centre itself.

Stores:

* Shopping centre name
* Up to 50 businesses
* Number of businesses currently added

Main responsibilities:

* Add businesses
* Store businesses using `Business*` pointers
* Manage restaurants and shops polymorphically
* Print business lists and statistics
* Search employees across all businesses
* Find the largest business
* Correctly delete dynamically allocated businesses

## Files

```text
Business.h
Business.cpp
Employee.h
Employee.cpp
Restaurant.h
Restaurant.cpp
Shop.h
Shop.cpp
ShoppingCentre.h
ShoppingCentre.cpp
shoppingmain.cpp
```

## Compilation

Compile all source files together using `g++`:

```bash
g++ -std=c++11 -Wall -Wextra shoppingmain.cpp Business.cpp Employee.cpp Restaurant.cpp Shop.cpp ShoppingCentre.cpp -o shopping
```

## Running the Program

After compilation, run:

```bash
./shopping
```

On Windows PowerShell, run:

```bash
.\shopping.exe
```

## Example Menu Options

The program allows the user to:

1. Add a business
2. Add an employee to a business
3. Print all businesses
4. Print all businesses with employees
5. Print shop statistics
6. Print shops by type
7. Print suitable restaurants
8. Search employees by name
9. Print the largest business
10. Exit

## Constraints

* Uses `char*` instead of `std::string`
* Uses fixed-size arrays instead of `std::vector`
* Avoids modern C++ features such as `auto`, `constexpr`, and STL containers
* Implements manual copy control where dynamic memory is used

## Notes

The system can store up to 50 businesses in a shopping centre. Each business can store up to 20 employees. Restaurants use type `0`, while shops use types `1` to `4`.

Shop type mapping:

```text
0 -> Restaurant
1 -> Clothing
2 -> Technology
3 -> Accessories
4 -> Beauty
```
