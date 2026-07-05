# Player

This folder contains a simple Java console application that demonstrates object-oriented programming using a player, a country, and a team.

The program asks the user to enter information about a player, the player's country, and the player's team. After collecting the information, it prints all details to the console.

## Files

```text
Player/
│
├── Country.java
├── Main.java
├── Player.java
├── Team.java
└── README.md
```

## Overview

The project is based on three main model classes:

* `Player`
* `Country`
* `Team`

The `Main` class runs the program and gets input from the user.

A `Player` object contains personal information and also has a `Country` object and a `Team` object. This shows how one class can use other classes as fields.

## Main Concepts Practiced

This exercise demonstrates the following Java concepts:

* Classes and objects
* Constructors
* Default constructors
* Parameterized constructors
* Encapsulation
* Private fields
* Getter and setter methods
* Object composition
* User input with `Scanner`
* Date parsing with `SimpleDateFormat`
* Working with `Date`
* Printing formatted output

## Class Descriptions

### `Player`

The `Player` class stores the player's personal information.

A player has:

* Name
* Surname
* Age
* Country
* Team

The class includes methods for:

* Adding country information
* Adding team information
* Printing player details

The player object contains both a `Country` object and a `Team` object.

### `Country`

The `Country` class stores information about a country.

A country has:

* Name
* Founder
* Form of government
* Continent
* Founding date

It also has a `printCountryDetails()` method that prints the country information.

### `Team`

The `Team` class stores information about a team.

A team has:

* Name
* League
* Founder
* Founding date

It also has a `printTeamDetails()` method that prints the team information.

### `Main`

The `Main` class contains the `main()` method.

It asks the user to enter:

* Player name
* Player surname
* Player age

Then it calls the methods for adding country and team information.

Finally, it prints all player details.

## Date Format

The program expects dates to be entered in the following format:

```text
dd/MM/yyyy
```

Example:

```text
29/10/1923
```

The date is parsed using `SimpleDateFormat`.

## Example Usage

```text
Enter Player name:
Lionel

Enter player surname:
Messi

Enter player age:
36

Enter country name:
Argentina

Enter country Founder:
Manuel Belgrano

Enter country form of government:
Federal presidential republic

Enter country continent:
South America

Enter country founding date:
09/07/1816

Enter the team name:
Inter Miami

Enter the league:
Major League Soccer

Enter the team founder:
David Beckham

Enter team founding date:
29/01/2018
```

Example output:

```text
Personal Information:

Player Name: Lionel
Player Surname: Messi
Player Age: 36
----------------------------------------------------------

Country Information:

Country name: Argentina
Country founder: Manuel Belgrano
Country form of government: Federal presidential republic
Country continent: South America
Country founding date: 1816-07-09
----------------------------------------------------------

Team Information:

Team Name: Inter Miami
Team League: Major League Soccer
Team Founder: David Beckham
Team Founding date: 2018-01-29
---------------------------------------------------------------------------
```

## How to Run

Open a terminal inside the `Player` folder.

Compile the Java files:

```bash
javac *.java
```

Run the program:

```bash
java Main
```
