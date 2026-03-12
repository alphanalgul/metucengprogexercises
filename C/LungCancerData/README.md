# Patient Data Processing Program

## Overview

This program reads patient information from a text file specified through command-line arguments, stores the data in an array of structures, and performs several operations on the dataset.

The program is designed to:

- Load patient records from a file
- Display all records in a formatted table
- Calculate basic statistics about patients
- Separate patients into two files based on lung cancer status

The program is written in **C** and uses **file handling**, **structures**, **dynamic memory allocation**, and **command-line arguments**.

---

## Features

The program performs the following tasks:

1. **Reads Patient Data**
   - Reads records from a file specified by the user.
   - Stores the data in an array of structures.

2. **Displays Patient Records**
   - Prints all patient records in a tabular format.

3. **Calculates Statistics**
   - Counts the number of:
     - Male patients
     - Female patients
     - Patients with lung cancer
     - Patients without lung cancer

4. **Splits the Dataset**
   - Creates two output files:
     - `cancer.txt` → patients diagnosed with lung cancer
     - `non_cancer.txt` → patients without lung cancer

---

## Data Structure

The program defines a structure to represent each patient:

```c
typedef struct Data{
    int id;
    char name[50];
    char surname[50];
    char gender[50];
    int smoking;
    char cancer[50];
} Data;
```
---

## Input File Format
```text
name,weight,length,date,city
Salmon,12,45.5,2024-01-15,Trabzon
Tuna,20,60.2,2024-02-10,Izmir
Carp,12,40.0,2024-03-05,Ankara
```
---

## Console Output
```text
ID  Name  Surname  Gender  Smoking  Lung_Cancer
1   John   Smith   M   1   Y
2   Alice  Brown   F   0   N
3   Mark   Taylor  M   1   N

2 patients with cancer and 1 patients without cancer
2 Male patients and 1 Female patients
Two files are created for you: cancer.txt and non_cancer.txt!
```
---

## Generated Files
### cancer.txt
```text
1 John Smith M 1 Y
4 Lisa Johnson F 0 Y
```

### non_cancer.txt
```text
2 Alice Brown F 0 N
3 Mark Taylor M 1 N
```

---
