# Simple Programs in C

This folder contains three short C programs written for basic programming practice.  
Each program focuses on a different concept such as loops, functions, arrays, random number generation, and simple data analysis.

## Programs Included

### 1. Eye Dilation Simulation
This program simulates eye dilation data for a number of users.

#### What it does
- Asks the user for the number of users
- Randomly generates:
  - iris radius
  - pupil radius
- Computes a **dilation ratio** using a custom formula
- Classifies each user into an age group:
  - **Young**
  - **Adult**
  - **Elderly**

#### Concepts used
- Functions
- Loops
- Random number generation
- Conditional statements

---

### 2. Cholesterol Level Analyzer
This program analyzes cholesterol level categories entered by the user for a lab.

#### What it does
- Asks the user for a **Lab ID**
- Accepts patient cholesterol categories as characters:
  - `D` / `d` → Dangerous
  - `R` / `r` → At Risk
  - `H` / `h` → Healthy
- Stops reading input when the user presses **Enter**
- Calculates and displays the percentage of patients in each category

#### Concepts used
- Character input
- Counters
- Percent calculations
- Conditional statements
- While loops

---

### 3. Mean Squared Error (MSE) Calculator
This program calculates the **Mean Squared Error (MSE)** between two vectors.

#### What it does
- Asks the user for the number of measurements
- Reads the first vector from user input
- Randomly generates the second vector
- Prints the predicted values
- Computes:

\[
MSE = \frac{\sum (A[i] - B[i])^2}{N}
\]

#### Concepts used
- Arrays and pointers
- Dynamic memory allocation
- Random number generation
- Mathematical calculations
- Functions

---
