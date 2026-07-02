# Simulation Modeling Exercises in C

## Description

This folder contains **C programming exercises** related to probability distributions, random number generation, and basic simulation modeling.

The programs were written as practice exercises for **CNG 476 / System Simulation** topics such as:

* random number generation
* random variate generation
* probability distributions
* sample mean and variance
* queue simulation
* Linear Congruential Generator
* Monte Carlo-style repeated experiments

Each program is independent and can be compiled/run separately.

---

## Programs Included

| Program                            | Source File      | Description                                                          |
| ---------------------------------- | ---------------- | -------------------------------------------------------------------- |
| Bernoulli Simulation               | `bernoulli.c`    | Simulates binary outcomes such as heads/tails using Bernoulli trials |
| Binomial Simulation                | `binomial.c`     | Simulates repeated Bernoulli trials and counts successes             |
| Exponential Repair Time Simulation | `exponential.c`  | Generates exponential repair/service times                           |
| Exponential Interval Counter       | `exponential2.c` | Generates exponential values and counts them in intervals            |
| FCFS Queue Simulation              | `fcfs-queue.c`   | Simulates a small First-Come First-Served queue                      |
| Geometric Simulation               | `geometric.c`    | Simulates number of trials until the first success                   |
| Linear Congruential Generator      | `lcg.c`          | Generates pseudo-random numbers using the LCG method                 |
| Poisson Arrival Simulation         | `poisson.c`      | Simulates Poisson arrivals using exponential interarrival times      |
| Uniform Random Number Simulation   | `uniform.c`      | Generates uniform random numbers and calculates sample statistics    |

---

# 1. Bernoulli Simulation

## File

```text
bernoulli.c
```

## Description

This program simulates **Bernoulli trials**.

Each trial has two possible outcomes:

* `1` → success / heads
* `0` → failure / tails

The program uses a success probability of:

```text
p = 0.6
```

It performs 200 trials, counts the number of successes and failures, and calculates sample mean and sample variance.

---

# 2. Binomial Simulation

## File

```text
binomial.c
```

## Description

This program simulates a **Binomial distribution**.

Each round contains 10 Bernoulli trials. The program repeats this for 200 rounds.

The success probability is:

```text
p = 0.8
```

For each round, the program counts the number of successes. Then it calculates:

* total number of successes
* maximum successes in a single round
* minimum successes in a single round
* success percentage
* sample mean
* sample variance

---

# 3. Exponential Repair Time Simulation

## File

```text
exponential.c
```

## Description

This program generates random repair times using the **Exponential distribution**.

The program uses inverse transform sampling:

```text
X = -(1 / lambda) * log(U)
```

where:

* `U` is a uniform random number between 0 and 1
* `lambda` is the rate parameter
* `X` is the generated exponential random variable

The program generates 120 repair times and calculates:

* sample mean
* sample variance

---

# 4. Exponential Interval Counter

## File

```text
exponential2.c
```

## Description

This program generates 1000 exponential random variables using:

```text
X = -log(U) / lambda
```

The rate parameter is:

```text
lambda = 1 / 4
```

So the theoretical mean is approximately:

```text
1 / lambda = 4
```

The program counts how many generated values fall into these intervals:

| Interval        |
| --------------- |
| `[0, 2)`        |
| `[2, 4)`        |
| `[4, 6)`        |
| `[6, 8)`        |
| `[8, infinity)` |

It also calculates the sample mean and sample variance.

---

# 5. FCFS Queue Simulation

## File

```text
fcfs-queue.c
```

## Description

This program simulates a small **First-Come First-Served queue**.

The user enters:

* customer arrival rate
* customer service rate

The program generates exponential interarrival and service times, then calculates queue timing values for 5 customers.

For each customer, the program calculates:

* arrival time
* service time
* service start time
* finish time
* waiting time
* system time

At the end, it prints:

* average waiting time
* average system time

---

# 6. Geometric Simulation

## File

```text
geometric.c
```

## Description

This program simulates a **Geometric distribution**.

It repeatedly performs Bernoulli trials until the first success occurs.

The success probability is:

```text
p = 0.15
```

The experiment is repeated 150 times. For each experiment, the program records how many trials were needed until the first success.

It then calculates:

* total number of trials
* average number of trials before success
* sample mean
* sample variance

---

# 7. Linear Congruential Generator

## File

```text
lcg.c
```

## Description

This program demonstrates the **Linear Congruential Generator** method for generating pseudo-random numbers.

The general LCG formula is:

```text
Xn+1 = (aXn + c) mod m
```

The generated integer values are usually converted into uniform values by dividing by the modulus:

```text
Ui = Xi / m
```


---

# 8. Poisson Arrival Simulation

## File

```text
poisson.c
```

## Description

This program simulates **Poisson arrivals** using exponential interarrival times.

The program uses the connection between the Poisson process and the Exponential distribution:

```text
Poisson process → number of arrivals in a fixed interval
Exponential distribution → time between arrivals
```

The program repeatedly generates exponential interarrival times and counts how many arrivals occur within one time unit.

It then calculates:

* theoretical mean
* theoretical variance
* sample mean
* sample variance

---

# 9. Uniform Random Number Simulation

## File

```text
uniform.c
```

## Description

This program generates 1000 random numbers from the continuous uniform distribution on:

```text
[0, 1]
```

It prints the generated values and calculates:

* minimum generated value
* maximum generated value
* theoretical mean
* theoretical variance
* sample mean
* sample variance


---

## How to Run

Each file can be compiled and run separately.

Because some programs use mathematical functions such as `log()` and `pow()`, it is safe to compile with `-lm`.

---

## Compile and Run Commands

### Bernoulli

```bash
gcc bernoulli.c -o bernoulli -lm
./bernoulli
```

### Binomial

```bash
gcc binomial.c -o binomial -lm
./binomial
```

### Exponential

```bash
gcc exponential.c -o exponential -lm
./exponential
```

### Exponential Interval Counter

```bash
gcc exponential2.c -o exponential2 -lm
./exponential2
```

### FCFS Queue

```bash
gcc fcfs-queue.c -o fcfs_queue -lm
./fcfs_queue
```

### Geometric

```bash
gcc geometric.c -o geometric -lm
./geometric
```

### Linear Congruential Generator

```bash
gcc lcg.c -o lcg -lm
./lcg
```

### Poisson

```bash
gcc poisson.c -o poisson -lm
./poisson
```

### Uniform

```bash
gcc uniform.c -o uniform -lm
./uniform
```

---

## Windows PowerShell Run Commands

After compiling, run the executable like this:

```bash
.\bernoulli.exe
.\binomial.exe
.\exponential.exe
.\exponential2.exe
.\fcfs_queue.exe
.\geometric.exe
.\lcg.exe
.\poisson.exe
.\uniform.exe
```

---

## Input Requirements

Most programs do not require external input files.

| Program          | External File Required? | Console Input Required?   |
| ---------------- | ----------------------- | ------------------------- |
| `bernoulli.c`    | No                      | No                        |
| `binomial.c`     | No                      | No                        |
| `exponential.c`  | No                      | No                        |
| `exponential2.c` | No                      | No                        |
| `fcfs-queue.c`   | No                      | Yes                       |
| `geometric.c`    | No                      | No                        |
| `lcg.c`          | No                      | Depends on implementation |
| `poisson.c`      | No                      | No                        |
| `uniform.c`      | No                      | No                        |

---

## Example FCFS Queue Input

```text
Enter the Customer Arrival Rate: 2
Enter Customer Service Rate: 3
```

The program then prints a table similar to:

```text
Customer | Arrival | Service | Start | Finish | Wait | System
1        | ...
2        | ...
3        | ...
4        | ...
5        | ...
```

---
