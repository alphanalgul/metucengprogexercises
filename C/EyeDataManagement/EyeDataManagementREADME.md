# Eye Data Management System

## Overview
The **Eye Data Management System** is a C program designed to read, store, and manage eye-tracking data for multiple users. The program processes measurements related to the **pupil and iris coordinates and radii** and organizes them using **linked lists**.

Each user has their own list of eye measurement records, and all users are maintained in a separate linked list structure.

The program also validates data, allows correction or deletion of invalid records, and provides statistics including the **number of eye measurements** and an **estimated age group** based on pupil dilation ratios.

---

## Features

- Reads eye-tracking data from a file
- Stores data using **linked lists**
- Maintains:
  - a **User linked list**
  - an **EyeData linked list** for each user
- Detects invalid data values (zero values)
- Allows users to:
  - delete invalid records
  - replace them with new values
- Performs **case-insensitive username search**
- Calculates:
  - number of eye measurements
  - estimated age group
- Interactive menu system
- Proper memory deallocation

---

## Data Structures

### EyeData Linked List
Each node represents one eye measurement.

| Field | Description |
|------|-------------|
| `PupilX` | X coordinate of pupil center |
| `PupilY` | Y coordinate of pupil center |
| `IrisX` | X coordinate of iris center |
| `IrisY` | Y coordinate of iris center |
| `IrisR` | Radius of the iris |
| `PupilR` | Radius of the pupil |
| `next` | Pointer to next eye data node |

---

### User Linked List
Each node represents a user.

| Field | Description |
|------|-------------|
| `UserName` | Name of the user |
| `eyeList` | Pointer to the linked list of eye data |
| `next` | Pointer to the next user node |

---

## Input File Format

The program expects a **CSV file** with the following structure:

| UserName | PupilX | PupilY | IrisX | IrisY | IrisR | PupilR |
|---------|--------|--------|-------|-------|-------|-------|
| Alice | 12 | 25 | 12 | 25 | 10 | 4 |
| Alice | 14 | 26 | 14 | 26 | 9 | 3 |
| Bob | 20 | 18 | 20 | 18 | 11 | 4 |
| Charlie | 30 | 22 | 30 | 22 | 13 | 5 |

Example file content:
Alice,12,25,12,25,10,4
Alice,14,26,14,26,9,3
Bob,20,18,20,18,11,4
Charlie,30,22,30,22,13,5

Each row represents **one eye measurement record**.

---

## Age Group Estimation

The program estimates the user's age group using the **average dilation ratio**:

| Ratio | Age Group |
|------|-----------|
| < 1.6 | Young |
| 1.6 – 4.6 | Adult |
| > 4.6 | Elderly |

The program calculates the **average ratio across all eye measurements for a user**.

---

## Program Workflow

1. The user enters the **input filename**.
2. The program loads the eye data into linked lists.
3. It checks for **invalid values (0 values)**.
4. If invalid values exist, the user is prompted to:
   - delete the record (`d`)
   - enter new values (`a`)
5. After validation, the user can access the menu.

---

## Menu Options

| Option | Description |
|------|-------------|
| `1` | Display statistics for a specific user |
| `0` | Exit the program |

Example menu:
(1) Display the statistics
(0) Exit
Enter your choice:

---

## Sample Program Execution
Enter file name: eyeData.txt
The eye data is successfully loaded.
(1) Display the statistics
(0) Exit
Enter your choice: 1

Enter a user name: Alice
Alice has 2 eye data and The age group for the eye data is: Adult

---

## Invalid Data Handling

If a record contains **zero values**, the program prompts the user:
Alice has eye data with zero value(s).
Would you like to delete (d) or add new value (a)?

- `d` → Deletes the record  
- `a` → Allows entering new measurement values

---

