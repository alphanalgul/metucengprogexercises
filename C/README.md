# C Programming Exercises

## Description

This directory contains C programming exercises, mini-projects, and course assignments developed during my Computer Engineering studies at METU NCC.

The projects cover introductory and intermediate C programming topics, including data structures, algorithms, file processing, simulations, operating systems concepts, and artificial intelligence search algorithms.

The purpose of this directory is to keep my C coursework organized and to show practical implementations of the concepts I studied in different Computer Engineering courses.

---

## Relevant Courses

* **CNG 140 – C Programming**
* **CNG 213 – Data Structures**
* **CNG 315 – Algorithms**
* **CNG 334 – Operating Systems**
* **CNG 462 – Artificial Intelligence**
* **CNG 476 – System Simulation**

---

## Featured Projects

### 1. Student Book Borrowing Management

A hash table based record management system for student book borrowing data.

This project demonstrates:

* hash tables
* linear probing
* quadratic probing
* double hashing
* collision handling
* rehashing
* file-based record loading

Folder:

```text
Student_Book_Borrowing_Management/
```

---

### 2. AVL Fishdom Analysis

A fish data analysis program that stores fish records in an AVL tree.

This project demonstrates:

* AVL trees
* self-balancing binary search trees
* tree rotations
* file processing
* sorted traversal
* finding maximum values in tree-based data

Folder:

```text
AVLFishdomAnalysis/
```

---

### 3. Transportation Company

A directed weighted graph project for modeling warehouse transportation routes.

This project demonstrates:

* graph representation
* adjacency lists
* weighted edges
* in-degree and out-degree analysis
* route distance calculations
* DFS-based path search

Folder:

```text
TransportationCompany/
```

---

### 4. Simulation Modeling Exercises

A collection of C programs for probability distributions, random variate generation, and basic simulation modeling.

This project demonstrates:

* Bernoulli distribution
* Binomial distribution
* Geometric distribution
* Poisson arrivals
* Exponential interarrival times
* Uniform random number generation
* Linear Congruential Generator
* FCFS queue simulation
* Monte Carlo simulation
* covariance and correlation

Folder:

```text
SimulationModeling/
```

---

### 5. Operating Systems Scheduling and Threading Exercises

C programs focused on operating systems concepts such as process scheduling, shared memory, process creation, threads, semaphores, and mutexes.

These projects demonstrate:

* Shortest Process Next scheduling
* Preemptive Priority Scheduling
* turnaround time and waiting time calculations
* `fork()`
* `mmap()`
* `wait()`
* POSIX threads
* semaphores
* mutex synchronization
* shared resource management

Suggested folder:

```text
OperatingSystems/
```

---

### 6. AI Search and Game Playing

A C project that combines graph search algorithms and game-playing AI.

This project demonstrates:

* Breadth-First Search
* Uniform Cost Search
* A* Search
* Greedy Best-First Search
* heuristic functions
* graph-based state spaces
* minimax game playing
* Poisonous Chocolate game simulation

Suggested folder:

```text
ArtificialIntelligence/
```

---

## Repository Structure

## Data Structures Projects

Core implementations of fundamental data structures and graph-based problems.

| Project                             | Description                                          |
| ----------------------------------- | ---------------------------------------------------- |
| `AVLFishdomAnalysis`                | AVL tree implementation for fish data analysis       |
| `BST`                               | Instructor record manager using a Binary Search Tree |
| `Student_Book_Borrowing_Management` | Hash table based student book borrowing system       |
| `SocialNetwork`                     | Directed graph social network analysis using DFS     |
| `TransportationCompany`             | Directed weighted graph for warehouse route analysis |
| `EyeDataManagement`                 | Linked list based eye data management system         |

---

## Data Management and File Processing Projects

Programs that read, process, analyze, and write structured data.

| Project                   | Description                                                            |
| ------------------------- | ---------------------------------------------------------------------- |
| `PatientRecords`          | Hospital patient record processing using structures and dynamic memory |
| `LungCancerData`          | Lung cancer patient dataset processing using command-line arguments    |
| `SummerInternshipProgram` | Internship record system with searching, sorting, and statistics       |
| `TeamForm`                | Football team data analyzer using structures and file processing       |
| `PlaneTicketProgram`      | Flight booking and investment simulator                                |

---

## Game and Logic Programs

Console-based games and logic simulations implemented in C.

| Project          | Description                                                                          |
| ---------------- | ------------------------------------------------------------------------------------ |
| `CircleGame`     | Board game simulation using arrays, random numbers, and traps                        |
| `CragGame`       | Dice-based Crag game simulation                                                      |
| `DropDeadGame`   | Dice-based Drop Dead game simulation                                                 |
| `FullSubtractor` | Digital logic simulation for a full subtractor                                       |
| `SimplePrograms` | Small introductory C programs for arrays, functions, random values, and calculations |

---

## System Simulation Projects

CNG 476 related programs for probability, distributions, and simulation modeling.

| Project                             | Description                                             |
| ----------------------------------- | ------------------------------------------------------- |
| `SimulationModeling/bernoulli.c`    | Bernoulli trial simulation                              |
| `SimulationModeling/binomial.c`     | Binomial random variable simulation                     |
| `SimulationModeling/geometric.c`    | Geometric distribution simulation                       |
| `SimulationModeling/poisson.c`      | Poisson arrival simulation                              |
| `SimulationModeling/exponential.c`  | Exponential random variate generation                   |
| `SimulationModeling/uniform.c`      | Uniform random number generation and sample statistics  |
| `SimulationModeling/lcg.c`          | Linear Congruential Generator                           |
| `SimulationModeling/fcfs-queue.c`   | Basic FCFS queue simulation                             |
| `SimulationModeling/q1.c` to `q6.c` | Exam-style simulation and statistics practice questions |

---

## Operating Systems Projects

CNG 334 related programs for process scheduling, inter-process communication, and thread synchronization.

| Project                            | Description                                                                                               |
| ---------------------------------- | --------------------------------------------------------------------------------------------------------- |
| `process_scheduling_ipc_threads.c` | Process scheduling simulation using SPN, preemptive priority scheduling, `fork()`, `mmap()`, and pthreads |
| `ev_charging_station_threads.c`    | EV charging station simulation using threads, mutexes, semaphores, and priority queue behavior            |

Suggested folder structure:

```text
OperatingSystems/
├── process_scheduling_ipc_threads.c
├── ev_charging_station_threads.c
└── README.md
```

---

## Artificial Intelligence Projects

CNG 462 related programs for graph search, informed search, and game-playing AI.

| Project                      | Description                                                                      |
| ---------------------------- | -------------------------------------------------------------------------------- |
| `ai_search_rescue_mission.c` | Rescue mission project using BFS, UCS, A*, Greedy Best-First Search, and minimax |
| `challenge2.txt`             | External labyrinth input file used by the Greedy Best-First Search challenge     |

Suggested folder structure:

```text
ArtificialIntelligence/
├── ai_search_rescue_mission.c
├── challenge2.txt
└── README.md
```

---

## Concepts Demonstrated

## C Programming

* functions
* arrays
* strings
* structs
* pointers
* dynamic memory allocation
* command-line arguments
* file input and output
* menu-driven programs
* modular program design

---

## Data Structures

* linked lists
* binary search trees
* AVL trees
* hash tables
* queues
* priority queues
* graphs
* adjacency lists
* arrays of structures

---

## Algorithms

* searching
* sorting
* tree traversal
* graph traversal
* DFS
* BFS
* Uniform Cost Search
* A* Search
* Greedy Best-First Search
* minimax
* hashing and collision resolution

---

## System Simulation

* uniform random number generation
* random variate generation
* Bernoulli trials
* Binomial distribution
* Geometric distribution
* Poisson process
* Exponential interarrival times
* Linear Congruential Generator
* Monte Carlo simulation
* FCFS queue simulation
* sample mean and variance
* covariance and correlation
* autocorrelation

---

## Operating Systems

* process scheduling
* Shortest Process Next
* Preemptive Priority Scheduling
* turnaround time
* waiting time
* process creation with `fork()`
* shared memory with `mmap()`
* synchronization with `wait()`
* POSIX threads
* mutexes
* semaphores
* shared resource management

---

## Artificial Intelligence

* state-space search
* uninformed search
* informed search
* heuristic functions
* path cost calculation
* graph-based problem solving
* game tree search
* minimax decision making
* simulation-based game analysis

---

## Compilation and Execution

Most programs can be compiled using GCC.

General format:

```bash
gcc file_name.c -o output_name
./output_name
```

Example:

```bash
gcc TreeADT.c -o bst
./bst
```

For programs that use math functions such as `log()`, `sqrt()`, or `pow()`, compile with `-lm`:

```bash
gcc file_name.c -o output_name -lm
./output_name
```

For programs that use POSIX threads, compile with `-pthread`:

```bash
gcc file_name.c -o output_name -pthread
./output_name
```

For programs that use both math functions and threads:

```bash
gcc file_name.c -o output_name -lm -pthread
./output_name
```

On Windows PowerShell, run executables like this:

```powershell
.\output_name.exe
```

---

