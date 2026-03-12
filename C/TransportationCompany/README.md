
# Warehouse Transportation Network (Graph)

## Description

This program models a **transportation network between warehouses**
using a **directed weighted graph**.

Each warehouse is represented as a vertex, and each delivery route
between warehouses is represented as a weighted edge indicating
the distance between locations.

The program reads warehouse and route data from input files and
performs various analyses on the transportation network.

---

## Data Structures Used

- Graph (Adjacency List Representation)
- Linked Lists
- Dynamic Memory Allocation

---

## Graph Representation

Each vertex represents a warehouse.

Each edge represents a delivery route:

Warehouse A --distance--> Warehouse B

---

## Input Files

### WarehouseLocations.txt

Contains the list of warehouse names.

Example:
```text
Ankara
Istanbul
Izmir
Adana
```
---
### WarehouseRoutes.txt

Contains the routes and distances between warehouses.

Example format:
```text
Ankara;200;Istanbul;300;Izmir
```
---

Meaning:

- Ankara → Istanbul (200 km)
- Ankara → Izmir (300 km)

---

## Program Features

The program performs several analyses on the network:

- Print all warehouse locations
- Print all transportation routes
- Find warehouses receiving deliveries from the most locations
- Find warehouses sending deliveries to the most locations
- Identify routes with the highest distance
- Identify routes with the lowest distance
- Find a path between two warehouses using DFS

---

## Example Analysis

The system can determine:

- The warehouse with the **most incoming routes**
- The warehouse with the **most outgoing routes**
- The **longest delivery route**
- The **shortest delivery route**

---

