# Internship Data Processor

## Description

- This project implements an **Internship Data Processing System** in **C**.
- The program reads student internship records from a **text file** passed as a **command-line argument**.
- After loading the data, the user can interact with the program using a menu.

The program allows the user to:

- Display all internship records
- Search for students by **name** or **full name**
- Sort records by **score** or **letter grade**
- Display **department-wise statistics** of passed and failed students

The program automatically assigns a **letter grade**:

| Score | Letter Grade |
|------|-------------|
| `>= 70` | `S` (Successful / Passed) |
| `< 70` | `U` (Unsuccessful / Failed) |

---

## Data Structure

The program stores internship data using the following structure:

```c
typedef struct {
    char name[NAME_LEN];
    char surname[SURNAME_LEN];
    int departmentCode;
    int semester;
    float score;
    char letterGrade;
} InternshipRecord;
```
---

## Features

- **Reads internship records from a file**
- **Automatically computes letter grades**
- **Supports searching by first name or full name**
- **Sorts data by score and letter grade**
- **Displays statistics for overall pass/fail and department-wise pass/fail**
- **Interactive menu system**

---

## Input File Format
```text
name surname departmentCode semester score
John Smith 355 6 85
Alice Brown 356 5 72
Mark White 365 7 64
Emily Stone 384 6 91
```
---
