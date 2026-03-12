# Student Book Borrowing Management System (Hash Table)

## Description

This program implements a **student book borrowing management system**
using a **hash table with open addressing**.

Each student is stored in the hash table and maintains a linked list of
borrowed books. The program allows users to manage borrowing records
efficiently using different collision resolution strategies.

The system reads borrowing records from a file and dynamically stores
them in the hash table.

---

## Data Structures Used

- Hash Table
- Linked Lists
- Dynamic Memory Allocation
- Struct-based record storage

---

## Hash Table Features

The hash table supports three collision resolution techniques:

1. Linear Probing
2. Quadratic Probing
3. Double Hashing

The program also implements **rehashing** when the load factor exceeds 0.5.

---

## Student Records

Each student contains:

- Student ID
- Student Name
- Borrow Count
- Linked list of borrowed books

Each borrowed book record includes:

- Borrow ID
- Book Title
- Author
- Borrow Date

---

## Program Features

The system provides a menu-driven interface with the following operations:

1. Print the hash table
2. Search for a student and display borrowing records
3. Return a borrowed book
4. Exit the program

---

## Hash Function

The hash key is computed by multiplying the non-zero digits of the student ID.

Example:

Student ID: `2035`

Key = 2 × 3 × 5

---

## Rehashing

When the load factor exceeds **0.5**, the table is resized to the next
prime number greater than double the current size.

---
