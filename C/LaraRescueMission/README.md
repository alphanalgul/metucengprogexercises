# Lara Rescue Mission

## Description

This project is an **Artificial Intelligence search and game-playing program** written in **C**.

The program is built around a rescue mission scenario where Agent Lara must choose a path through a survival map and complete different AI challenges. It demonstrates several AI concepts, including uninformed search, informed search, graph representation, heuristics, and minimax game playing.

The project includes:

* Breadth-First Search
* Uniform Cost Search
* A* Search
* Greedy Best-First Search
* Graph representation using adjacency lists
* Heuristic functions
* Path reconstruction using parent pointers
* Poisonous Chocolate game
* Minimax-based AI player
* Randomized simulation of 100 games

---

## Recommended File Name

```text
ai_search_rescue_mission.c
```

---

## Program Overview

The program starts by creating a survival map.

The map contains:

* Start
* Safehouse
* Challenge 1
* Challenge 2
* Exit

The user chooses which search algorithm to apply on the survival map:

| Option | Algorithm            |
| -----: | -------------------- |
|    `1` | Uniform Cost Search  |
|    `2` | Breadth-First Search |

After the search, the program moves to the selected challenge depending on the solution path.

---

## Survival Map

The survival map is represented as a directed weighted graph.

```text
Start(S) -> Safehouse(F)          cost 80
Start(S) -> Challenge 1 (C1)      cost 99
Safehouse(F) -> Challenge 2 (C2)  cost 97
Challenge 1 (C1) -> Exit(E)      cost 211
Challenge 2 (C2) -> Exit(E)      cost 101
```

The two main possible paths are:

| Path                                                      | Total Cost |
| --------------------------------------------------------- | ---------: |
| `Start(S) -> Challenge 1 (C1) -> Exit(E)`                 |        310 |
| `Start(S) -> Safehouse(F) -> Challenge 2 (C2) -> Exit(E)` |        278 |

Uniform Cost Search chooses the lower-cost path through the safehouse.

Breadth-First Search chooses the path with fewer levels based on expansion order.

---

## Data Structures Used

The graph is implemented using an adjacency list.

### Arc Structure

```c
struct arc {
    int distance;
    struct vertex *destination;
    struct arc *next;
};
```

### Vertex Structure

```c
struct vertex {
    struct vertex *next;
    struct vertex *parent;
    char node_name[50];
    int cost;
    int in_degree;
    int out_degree;
    int processed;
    int coordinate_1;
    int coordinate_2;
    struct arc *first;
};
```

### Graph Head Structure

```c
struct graph_head {
    int count;
    struct vertex *first;
};
```

---

## Search Algorithms

## 1. Breadth-First Search

Breadth-First Search expands nodes level by level.

In this project, BFS is used on the survival map to find a path from:

```text
Start(S)
```

to:

```text
Exit(E)
```

BFS does not consider path cost. It focuses on reaching the goal by graph depth.

---

## 2. Uniform Cost Search

Uniform Cost Search expands the node with the lowest total path cost.

In this project, UCS is used on the survival map and finds the lower-cost path:

```text
Start(S) -> Safehouse(F) -> Challenge 2 (C2) -> Exit(E)
```

This path has total cost:

```text
278
```

---

## 3. A* Search

Challenge 1 uses A* Search.

The challenge uses state-space search. Each state is represented as:

```text
(G, P, B)
```

Where:

| Symbol | Meaning                         |
| ------ | ------------------------------- |
| `G`    | Number of guards on one side    |
| `P`    | Number of prisoners on one side |
| `B`    | Boat position                   |

The program uses a heuristic function to guide A*:

```c
int heuristic_challenge1(struct vertex *current) {
    int G, P, B;
    sscanf(current->node_name, "(%d,%d,%d)", &G, &P, &B);
    return (G + P + 1) / 2;
}
```

A* combines:

```text
f(n) = g(n) + h(n)
```

where:

* `g(n)` is the cost from the start node
* `h(n)` is the heuristic estimate to the goal

---

## 4. Greedy Best-First Search

Challenge 2 uses Greedy Best-First Search.

The graph is loaded from an external file named:

```text
challenge2.txt
```

Each room has coordinates, and the heuristic is based on Manhattan distance:

```c
int heuristic(struct vertex *current, struct vertex *goal) {
    return abs(current->coordinate_1 - goal->coordinate_1)
         + abs(current->coordinate_2 - goal->coordinate_2);
}
```

Greedy Best-First Search expands the node with the lowest heuristic value:

```text
lowest h(n)
```

It does not guarantee the optimal path because it ignores total path cost.

---

## Challenge 1: Guards, Prisoners, and Boat

Challenge 1 is a state-space search problem.

The goal is to move guards and prisoners safely using a boat.

A state is invalid if, on either side of the river, prisoners outnumber guards while at least one guard is present.

A* Search is used to find a valid sequence of boat moves.

The program prints:

* Challenge 1 graph
* A* expansion order
* Total cost
* Solution path

---

## Challenge 2: Labyrinth Search

Challenge 2 loads a labyrinth graph from:

```text
challenge2.txt
```

The file contains:

* room names
* room coordinates
* neighboring rooms
* mad scientist room
* exit room

The program performs two Greedy Best-First Search runs:

1. Start room to mad scientist room
2. Mad scientist room to exit room

The default start room is:

```text
A2
```

---

## challenge2.txt Format

The file should contain lines for the mad scientist room and exit room:

```text
mad scientist ROOM_NAME
exit ROOM_NAME
```

Then each room line should follow this format:

```text
RoomName coordinate1 coordinate2 Neighbor1 Neighbor2 Neighbor3 Neighbor4
```

A room may have fewer than four neighbors.

Example:

```text
mad scientist D4
exit F6
A2 0 0 B2 A3
B2 1 0 A2 C2
A3 0 1 A2 B3
D4 3 3 C4 D5
F6 5 5 E6
```

---

## Poisonous Chocolate Game

The project also includes a Poisonous Chocolate game.

The game supports:

| Option | Mode                       |
| -----: | -------------------------- |
|    `1` | Human vs Human             |
|    `2` | Human vs AI                |
|    `3` | Lara Simulation, 100 games |
|    `4` | Exit                       |

The board size can be between:

```text
2x2
```

and:

```text
5x5
```

The user chooses the poisonous square.

---

## Game Rule

Players choose a chocolate square. When a square is chosen, all pieces to the right and below that square are removed.

The player who is forced to eat the poisonous piece loses.

---

## AI Player

The AI uses the **minimax algorithm**.

The minimax functions are:

```c
int max_value(struct Chocolate c, long long *nodeCount);
int min_value(struct Chocolate c, long long *nodeCount);
struct Move mini_max(struct Chocolate c, long long *nodeCount);
```

The program also counts how many game states are visited by minimax.

---

## Lara Simulation

The Lara simulation runs 100 games.

In this mode:

* Lara chooses legal moves randomly.
* The AI chooses moves using minimax.
* The program counts how many times Lara wins and how many times the AI wins.
* It displays winning percentages.

---

## Features

* Directed weighted graph implementation
* Adjacency list representation
* BFS search
* UCS search
* A* search
* Greedy Best-First Search
* Priority queue implementation
* Queue implementation
* Parent pointers for solution path printing
* Heuristic functions
* External labyrinth file loading
* Poisonous Chocolate game
* Human vs Human gameplay
* Human vs AI gameplay
* Minimax AI
* 100-game random simulation

---

## How to Run

### Compile

```bash
gcc ai_search_rescue_mission.c -o ai_search_rescue_mission
```

### Run

```bash
./ai_search_rescue_mission
```

On Windows PowerShell:

```bash
.\ai_search_rescue_mission.exe
```

---

## Input Requirements

The program takes input from the console.

The user selects:

1. Search algorithm for the survival map
2. Poisonous Chocolate game mode
3. Board size
4. Poison square location
5. Human moves during gameplay

---

## External File Requirement

Challenge 2 requires an external file named:

```text
challenge2.txt
```

This file should be in the same folder as the executable.

Example folder structure:

```text
AI_Search_GamePlaying/
├── ai_search_rescue_mission.c
├── challenge2.txt
└── README.md
```

If `challenge2.txt` is missing, the Challenge 2 part may fail.

---

## Example Usage

```text
Survival Map:
Start(S): Safehouse(F) 80, Challenge 1 (C1) 99,
Safehouse(F): Challenge 2 (C2) 97,
Challenge 1 (C1): Exit (E) 211,
Challenge 2 (C2): Exit (E) 101,

Welcome to Agent Lara's Rescue Mission -2> choose the Algorithm to Apply:
1)UCS
2)BFS
Choice:
```

Example input:

```text
1
```

This selects Uniform Cost Search.

---

## Example Poisonous Chocolate Input

```text
Poisonous Chocolate Bar Game
1.Human vs Human
2.Human vs AI
3.Lara Simulation 100 Games
4.Exit
Enter choice: 2

Enter number of rows (2 to 5): 4
Enter number of columns (2 to 5): 4
Enter poisonous square row (1 to 4): 1
Enter poisonous square column (1 to 4): 1
Do you want to start first? 1 = yes, 0 = no: 1
```

---
* Structs and pointers in C

