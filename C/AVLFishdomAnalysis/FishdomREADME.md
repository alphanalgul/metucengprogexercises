# Fishdom AVL Tree Analysis

## Overview
This program reads fish records from a CSV file and stores them in an AVL tree ordered by **weight**.  
It allows the user to:

- Read and parse fish data from a file
- Insert fish records into a balanced AVL tree
- Store multiple fish with the same weight in the same node
- Display all fish in ascending order of weight
- Display the heaviest fish
- Display the longest fish

The AVL tree keeps the data balanced, which improves insertion and lookup efficiency compared to a normal binary search tree.

---

## Features

- **CSV file input**
- **AVL tree insertion by weight**
- **Handling duplicate weights**
- **Sorted display of all fish records**
- **Search for heaviest fish**
- **Search for longest fish**
- **Interactive menu-driven interface**

---

## Data Format

The program expects the input file to contain fish records in the following format:

```text
name,weight,length,date,city
Salmon,12,45.5,2024-01-15,Trabzon
Tuna,20,60.2,2024-02-10,Izmir
Carp,12,40.0,2024-03-05,Ankara
