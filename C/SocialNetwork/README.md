
# Social Network Graph Analysis

## Description

This program simulates a **social network** using a **directed graph**.

Each user is represented as a vertex, and each friendship or follow
relationship is represented as a directed edge.

The system allows analysis of relationships between users and
performs graph-based operations such as finding the most followed user
and searching for connections between users.

---

## Data Structures Used

- Graph (Adjacency List Representation)
- Linked Lists
- Depth First Search (DFS)

---

## Graph Model

Users are nodes in the graph.

Friendships or follow relationships are directed edges.

Example:

John → Alice

means **John follows Alice**.

---

## Program Features

The program provides an interactive menu:

1. Depth-first search to find a connection path between two users
2. Find the user with the most followers
3. Find the user who follows the most users
4. Exit the program

---

## Example Users

The network includes users such as:

- John
- Alice
- Bob
- David
- Eve
- Frank

Friendships are defined programmatically.

---

## DFS Path Search

The program uses **Depth First Search (DFS)** to determine
whether a connection path exists between two users.

Example:
John → Alice → David
