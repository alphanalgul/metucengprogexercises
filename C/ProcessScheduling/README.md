
# Process Scheduling Simulation

## Description

This project is a **process scheduling simulation** written in **C**.

The program generates a set of random processes and simulates different scheduling-related operations.

---

## Program Behavior

The program creates 10 random processes.

Each process has:

* process ID
* burst time
* priority
* arrival time

Then the program performs the following operations:

1. Initializes a process queue with random values.
2. Sorts the processes by arrival time.
3. Sorts the processes by priority.
4. Executes the processes using **Shortest Process Next** scheduling.
5. Executes the processes using **Preemptive Priority Scheduling**.
6. Allocates a shared process queue using `mmap()`.
7. Creates a child process using `fork()`.
8. The child process sorts the shared queue.
9. The parent process waits for the child using `wait()`.
10. The parent reads the updated shared queue.
11. Creates two threads:

    * Thread 1 sorts the process queue by priority.
    * Thread 2 executes the queue using preemptive priority scheduling.

---

## Process Structure

Each process is represented using the following structure:

```c
typedef struct {
    int pid;
    int burst_time;
    int priority;
    int arrival_time;
} Process;
```

---

## Process Attributes

| Attribute      | Description                   |      Range |
| -------------- | ----------------------------- | ---------: |
| `pid`          | Process ID                    |    1 to 10 |
| `burst_time`   | Required execution time       | 5 to 25 ms |
| `priority`     | Process priority              |    1 to 10 |
| `arrival_time` | Time when the process arrives | 0 to 20 ms |

A larger priority value means a higher-priority process.

---

## Scheduling Algorithms

## 1. Shortest Process Next

The **Shortest Process Next** algorithm is a non-preemptive scheduling algorithm.

At each decision point, the scheduler selects the arrived process with the shortest burst time.

Once a process starts running, it continues until completion.

The program prints which process is running at each time unit.

---

## 2. Preemptive Priority Scheduling

The **Preemptive Priority Scheduling** algorithm selects the arrived process with the highest priority.

The scheduler checks the process queue at every time unit.

If a higher-priority process is available, the CPU switches to that process.

In this program:

```text
larger priority value = higher priority
```

---

## Sorting Modes

The program includes a sorting function:

```c
void sortProcesses(Process queue[], int n, int mode);
```

The `mode` parameter controls the sorting behavior.

| Mode | Sorting Type                                                |
| ---: | ----------------------------------------------------------- |
|  `1` | Sort by arrival time                                        |
|  `2` | Sort by priority, then arrival time if priorities are equal |

---

## IPC and Threading Features

## Shared Memory with `mmap()`

The program uses `mmap()` to allocate a shared process queue:

```c
Process *process_queue = mmap(NULL, 10 * sizeof(Process),
                              PROT_READ | PROT_WRITE,
                              MAP_SHARED | MAP_ANONYMOUS,
                              0, 0);
```

This allows the parent and child process to access the same memory region.

---

## Process Creation with `fork()`

The program creates a child process using:

```c
pid_t p = fork();
```

The child process sorts the shared process queue.

The parent process waits until the child finishes:

```c
wait(NULL);
```

Then the parent reads the updated shared queue.

---

## Threads with `pthread`

The program creates two threads:

| Thread   | Task                                                           |
| -------- | -------------------------------------------------------------- |
| Thread 1 | Sorts the process queue by priority                            |
| Thread 2 | Executes the sorted queue using preemptive priority scheduling |

The program uses `pthread_join()` to wait for each thread to finish.

---

## Features

* Random process generation
* Process queue printing
* Sorting by arrival time
* Sorting by priority
* Shortest Process Next scheduling
* Preemptive Priority scheduling
* Turnaround time calculation
* Waiting time calculation
* Shared memory with `mmap()`
* Child process creation with `fork()`
* Parent process synchronization with `wait()`
* Thread creation with `pthread_create()`
* Thread synchronization with `pthread_join()`

---

## How to Run

This program uses Unix/Linux system calls such as:

* `fork()`
* `mmap()`
* `wait()`
* `pthread`

Because of this, it should be compiled and run on **Linux**, **macOS**, or **Windows Subsystem for Linux (WSL)**.

It will not run directly in normal Windows Command Prompt or PowerShell without WSL.

---

## Recommended File Name

```text
process_scheduling_ipc_threads.c
```

---

## Compile

```bash
gcc process_scheduling_ipc_threads.c -o process_scheduling_ipc_threads -pthread
```

---

## Run

```bash
./process_scheduling_ipc_threads
```

---

## Input Requirements

No external input file is required.

No console input is required.

All process values are randomly generated by the program.

The random values change on each run because the program uses:

```c
srand(time(NULL));
```

---

## Example Output

The program prints randomly generated process information:

```text
Process ID: 1
Process Burst Time: 12
Process Arrival Time: 4
Process Priority: 8
```

It also prints execution steps:

```text
Time 0: Process 3 is running
Time 1: Process 3 is running
Time 2: Process 5 is running
```

At the end of each scheduling simulation, it prints turnaround and waiting times:

```text
Turnaround and Waiting Times:
Process 1, Turnaround Time: 18, Waiting Time: 6
Process 2, Turnaround Time: 25, Waiting Time: 10
```

---
