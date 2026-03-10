# Hospital Patient Record Processing Program

## Overview
This C program reads patient records from a file named `data.txt`, stores them dynamically using a `struct`, displays all patient information, calculates simple statistics, and separates the records into two output files:

- `cancer.txt` → patients diagnosed with lung cancer  
- `noncancer.txt` → patients without lung cancer  

The program demonstrates:
- file handling
- dynamic memory allocation
- structures
- string tokenization
- basic statistics
- writing data into separate files

---

## Features
The program performs the following tasks:

1. Opens and reads patient data from `data.txt`
2. Stores each patient record in a dynamically allocated array of structures
3. Displays all patient records on the screen
4. Calculates:
   - number of male and female patients
   - number of patients with and without lung cancer
5. Creates two output files:
   - `cancer.txt`
   - `noncancer.txt`
6. Frees all dynamically allocated memory before exiting

---

# Input File Format

| ID | Name  | Surname | Gender | Smoking | Lung_Cancer |
|----|------|--------|--------|--------|-------------|
| 1  | John | Smith  | M      | 1      | Y |
| 2  | Alice | Brown | F      | 0      | N |
| 3  | David | White | M      | 1      | Y |
| 4  | Emma | Green  | F      | 0      | N |

---

# Sample Output

## Patients Table

| ID | Name  | Surname | Gender | Smoking | Lung_Cancer |
|----|------|--------|--------|--------|-------------|
| 1  | John | Smith  | M      | 1      | Y |
| 2  | Alice | Brown | F      | 0      | N |
| 3  | David | White | M      | 1      | Y |
| 4  | Emma | Green  | F      | 0      | N |

---

## Statistics

| Statistic | Value |
|----------|------|
| Patients with cancer | 2 |
| Patients without cancer | 2 |
| Male patients | 2 |
| Female patients | 2 |

---

## Generated Files

| File Name | Description |
|----------|-------------|
| `cancer.txt` | Contains records of patients with lung cancer |
| `noncancer.txt` | Contains records of patients without lung cancer |

The program prints:

Two files are created for you: cancer.txt and noncancer.txt!

---
