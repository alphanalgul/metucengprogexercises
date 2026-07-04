# EV Charging Station Thread Simulation

## Description

This project is an **Electric Vehicle Charging Station simulation** written in **C**.

The program simulates a charging station where normal and emergency vehicles arrive randomly. Each vehicle is represented by a separate thread. The charging station is also represented by a separate thread.

The program uses:

* POSIX threads
* mutex locks
* semaphores
* random vehicle arrivals
* priority queue behavior for emergency vehicles

---

## Program Behavior

The program randomly generates:

* number of waiting slots
* number of vehicles
* vehicle type
* vehicle charging time
* vehicle arrival delay

Each vehicle can be one of two types:

| Type | Meaning           |
| ---- | ----------------- |
| `N`  | Normal vehicle    |
| `E`  | Emergency vehicle |

The charging station can charge only one vehicle at a time.

When a vehicle arrives:

1. If the station is free, the vehicle starts charging immediately.
2. If the station is busy and the waiting queue has space, the vehicle joins the queue.
3. If the station is busy and the queue is full, the vehicle leaves.
4. Emergency vehicles are placed before normal vehicles in the queue.
5. The station charges vehicles one by one.
6. The simulation ends when all vehicles have either charged or left.

---

## Vehicle Structure

Each vehicle is represented using this structure:

```c
struct Vehicle {
    int id;
    char type;
    int charge_time;
    struct Station *station;
};
```

| Field         | Description                            |
| ------------- | -------------------------------------- |
| `id`          | Vehicle ID                             |
| `type`        | `N` for normal or `E` for emergency    |
| `charge_time` | Charging duration                      |
| `station`     | Pointer to the shared charging station |

---

## Station Structure

The charging station is represented using this structure:

```c
struct Station {
    struct Vehicle queue[5];

    int vehicle_number;
    int slots;
    int total_vehicle;
    int finished_vehicle;

    int busy;
    int has_vehicle;
    struct Vehicle vehicle;

    sem_t semaphore;
    pthread_mutex_t mutex;
};
```

The station stores:

* waiting queue
* number of waiting slots
* number of vehicles in the queue
* number of completed/left vehicles
* current vehicle being charged
* semaphore for waking the station thread
* mutex for protecting shared data

---

## Queue Behavior

The queue can contain up to 5 vehicles.

Normal vehicles are inserted at the back of the queue.

Emergency vehicles are also inserted first at the back, but then shifted forward until they are placed before normal vehicles.

Example:

```text
Queue: N1 N2 N3
```

If emergency vehicle `E4` arrives:

```text
Queue: E4 N1 N2 N3
```

Emergency vehicles are prioritized over normal vehicles, but the program still keeps the queue order among vehicles of the same type.

---

## Thread Behavior

## Vehicle Threads

Each vehicle has its own thread.

A vehicle thread:

1. Sleeps for a random time to simulate random arrival.
2. Locks the station mutex.
3. Checks whether the station is free, busy, or full.
4. Starts charging, waits in queue, or leaves.
5. Signals the station using a semaphore if needed.
6. Unlocks the mutex.

---

## Station Thread

The station thread:

1. Waits on the semaphore.
2. Locks the mutex.
3. Selects the current vehicle or the next vehicle from the queue.
4. Unlocks the mutex.
5. Sleeps for the vehicle's charging time.
6. Marks the vehicle as finished.
7. Repeats until all vehicles are finished or have left.

---

## Synchronization Used

The program uses two synchronization tools.

### Mutex

The mutex protects shared station data:

```c
pthread_mutex_t mutex;
```

It prevents multiple vehicle threads from modifying the queue at the same time.

---

### Semaphore

The semaphore wakes the charging station when a vehicle is available:

```c
sem_t semaphore;
```

The station waits using:

```c
sem_wait(&station->semaphore);
```

Vehicle threads wake the station using:

```c
sem_post(&station->semaphore);
```

---

## Features

* Random number of vehicles
* Random number of waiting slots
* Random vehicle type generation
* Random vehicle arrival times
* Random charging times
* Vehicle thread for each vehicle
* Separate charging station thread
* Mutex-based queue protection
* Semaphore-based station signaling
* Emergency vehicle priority
* Full queue handling
* Charging completion tracking

---

## How to Run

This program uses POSIX threading and semaphore features.

It is recommended to run it on:

* Linux
* Ubuntu
* WSL on Windows

It will not run directly in normal Windows Command Prompt or PowerShell unless you use WSL or a POSIX-compatible environment.

---

## Recommended File Name

```text
ev_charging_station_threads.c
```

---

## Compile

```bash
gcc ev_charging_station_threads.c -o ev_charging_station_threads -pthread
```

---

## Run

```bash
./ev_charging_station_threads
```

---

## Input Requirements

No external input file is required.

No console input is required.

All values are generated randomly by the program.

---

## Randomly Generated Values

| Value                   |            Range |
| ----------------------- | ---------------: |
| Number of waiting slots |           1 to 5 |
| Number of vehicles      |          2 to 10 |
| Vehicle arrival delay   |  1 to 10 seconds |
| Vehicle charging time   | 1 to 200 seconds |
| Vehicle type            |       `N` or `E` |

---

## Example Output

```text
Number of waiting slots: 3
Number of vehicles: 5

N1 arrived with charging time 42
N1 starts charging

E2 arrived with charging time 18
E2 waits in the queue

Queue: E2 Empty Empty

Charging station: Busy

Vehicle N1 finished charging.
```

---

