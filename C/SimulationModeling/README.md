# Simulation Modeling Exercises in C

## Description

This folder contains **C programming exercises** related to probability distributions, random number generation, random variate generation, and basic simulation modeling.

* basic simulation exam-style coding questions

Each file is independent and can be compiled and run separately.

---

## Programs Included

| Program                            | Source File      | Description                                                                         |
| ---------------------------------- | ---------------- | ----------------------------------------------------------------------------------- |
| Bernoulli Simulation               | `bernoulli.c`    | Simulates binary outcomes using Bernoulli trials                                    |
| Binomial Simulation                | `binomial.c`     | Simulates repeated Bernoulli trials and counts successes                            |
| Exponential Repair Time Simulation | `exponential.c`  | Generates exponential repair/service times                                          |
| Exponential Interval Counter       | `exponential2.c` | Generates exponential values and counts them in intervals                           |
| FCFS Queue Simulation              | `fcfs-queue.c`   | Simulates a small First-Come First-Served queue                                     |
| Geometric Simulation               | `geometric.c`    | Simulates number of trials until the first success                                  |
| Linear Congruential Generator      | `lcg.c`          | Generates pseudo-random numbers using the LCG method                                |
| Poisson Arrival Simulation         | `poisson.c`      | Simulates Poisson arrivals using exponential interarrival times                     |
| Uniform Random Number Simulation   | `uniform.c`      | Generates uniform random numbers and calculates sample statistics                   |
| LCG Exponential Arrival Times      | `q1.c`           | Uses LCG-generated random numbers to generate customer arrival times                |
| Dice Roll Frequency Analysis       | `q2.c`           | Simulates 1000 dice rolls and compares empirical/theoretical results                |
| Monte Carlo Pi Estimation          | `q3.c`           | Estimates pi using random points inside a quarter circle                            |
| Uniform Randomness Test            | `q4.c`           | Counts uniform values in intervals and calculates sample statistics/autocorrelation |
| Monte Carlo Pi with Dry Run        | `q5.c`           | Estimates pi and includes a small dry-run explanation                               |
| Correlation Calculator             | `q6.c`           | Calculates covariance, correlation coefficient, and relationship direction          |

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

So the theoretical mean is:

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

This program demonstrates the **Linear Congruential Generator (LCG)** method for generating pseudo-random numbers.

The LCG formula is:

```text
X(n+1) = (aX(n) + c) mod m
```

The generated integer values are converted into uniform values using:

```text
U(i) = X(i) / m
```

The user enters:

* multiplier `a`
* increment `c`
* modulus `m`
* seed value
* number of values to generate

The program prints:

* generated `Xi` values
* generated `Ui` values
* sample mean
* sample variance

---

# 8. Poisson Arrival Simulation

## File

```text
poisson.c
```

## Description

This program simulates **Poisson arrivals** using exponential interarrival times.

The program uses the relationship between the Poisson process and the Exponential distribution:

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

# 10. LCG Exponential Arrival Times

## File

```text
q1.c
```

## Description

This program uses a **Linear Congruential Generator** to generate uniform random numbers, then converts them into exponential interarrival times.

The arrival times are used to display the expected arrival time of 10 customers starting from 09:00.

The program uses fixed LCG constants and a fixed seed.

---

# 11. Dice Roll Frequency Analysis

## File

```text
q2.c
```

## Description

This program simulates rolling a fair six-sided die 1000 times.

It counts how many times each face appears and calculates the empirical probability for each face.

The program also calculates:

* theoretical mean
* theoretical variance
* empirical mean
* empirical variance

---

# 12. Monte Carlo Pi Estimation

## File

```text
q3.c
```

## Description

This program estimates the value of pi using the **Monte Carlo method**.

The user enters the number of random points `N`.

For each point:

* `x` is generated from `U(0,1)`
* `y` is generated from `U(0,1)`
* the program checks whether the point is inside the quarter circle

A point is counted as inside if:

```text
x² + y² <= 1
```

The pi estimate is calculated using:

```text
pi ≈ 4 * (inside points / total points)
```

The program also calculates the absolute error compared to `3.141593`.

---

# 13. Uniform Randomness Test

## File

```text
q4.c
```

## Description

This program generates 1000 uniform random numbers in the interval:

```text
[0, 1)
```

It counts how many generated values fall into these intervals:

| Interval     |
| ------------ |
| `[0, 0.2)`   |
| `[0.2, 0.4)` |
| `[0.4, 0.6)` |
| `[0.6, 0.8)` |
| `[0.8, 1)`   |

The program also calculates:

* theoretical mean
* theoretical variance
* sample mean
* sample variance
* lag-1 sample autocorrelation

A small dry-run section is also included to demonstrate interval counting with fixed example values.

---

# 14. Monte Carlo Pi with Dry Run

## File

```text
q5.c
```

## Description

This program also estimates pi using the **Monte Carlo method**.

The user enters the number of random points `N`.

For each point:

* `x` is generated from `U(0,1)`
* `y` is generated from `U(0,1)`
* the program checks whether the point is inside the quarter circle

The program calculates:

* number of inside points
* Monte Carlo estimate of pi
* absolute error compared to `3.141593`

It also includes a dry-run explanation using three fixed points.

---

# 15. Correlation Calculator

## File

```text
q6.c
```

## Description

This program calculates the relationship between two integer arrays `X` and `Y`.

The user enters the value of `n`, then enters `n` values for `X` and `n` values for `Y`.

The program calculates:

* mean of `X`
* mean of `Y`
* covariance
* standard deviation of `X`
* standard deviation of `Y`
* correlation coefficient `r`

Then it classifies the relationship as:

* positive relationship
* negative relationship
* zero-based relationship

---

## How to Run

Each file can be compiled and run separately.

Because several programs use mathematical functions such as `log()`, `sqrt()`, and `pow()`, compile with `-lm`.

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

### Question 1 - LCG Exponential Arrival Times

```bash
gcc q1.c -o q1 -lm
./q1
```

### Question 2 - Dice Roll Frequency Analysis

```bash
gcc q2.c -o q2 -lm
./q2
```

### Question 3 - Monte Carlo Pi Estimation

```bash
gcc q3.c -o q3 -lm
./q3
```

### Question 4 - Uniform Randomness Test

```bash
gcc q4.c -o q4 -lm
./q4
```

### Question 5 - Monte Carlo Pi with Dry Run

```bash
gcc q5.c -o q5 -lm
./q5
```

### Question 6 - Correlation Calculator

```bash
gcc q6.c -o q6 -lm
./q6
```

---

## Windows PowerShell Run Commands

After compiling, run the executables like this:

```powershell
.\bernoulli.exe
.\binomial.exe
.\exponential.exe
.\exponential2.exe
.\fcfs_queue.exe
.\geometric.exe
.\lcg.exe
.\poisson.exe
.\uniform.exe
.\q1.exe
.\q2.exe
.\q3.exe
.\q4.exe
.\q5.exe
.\q6.exe
```

---

## Input Requirements

Most programs do not require external input files.

| Program          | External File Required? | Console Input Required?                                      |
| ---------------- | ----------------------- | ------------------------------------------------------------ |
| `bernoulli.c`    | No                      | No                                                           |
| `binomial.c`     | No                      | No                                                           |
| `exponential.c`  | No                      | No                                                           |
| `exponential2.c` | No                      | No                                                           |
| `fcfs-queue.c`   | No                      | Yes, user enters arrival rate and service rate               |
| `geometric.c`    | No                      | No                                                           |
| `lcg.c`          | No                      | Yes, user enters `a`, `c`, `m`, `seed`, and number of values |
| `poisson.c`      | No                      | No                                                           |
| `uniform.c`      | No                      | No                                                           |
| `q1.c`           | No                      | No                                                           |
| `q2.c`           | No                      | No                                                           |
| `q3.c`           | No                      | Yes, user enters `N`                                         |
| `q4.c`           | No                      | No                                                           |
| `q5.c`           | No                      | Yes, user enters `N`                                         |
| `q6.c`           | No                      | Yes, user enters array size and array values                 |

---

## Example Inputs

### FCFS Queue

```text
Enter the Customer Arrival Rate: 2
Enter Customer Service Rate: 3
```

### LCG

```text
Enter a,c,m,seed and number of values: 5 3 16 7 10
```

### Monte Carlo Pi

```text
Enter the value of N: 10000
```

### Correlation Calculator

```text
Enter a value n: 5
Enter values for X:
1 2 3 4 5
Enter values for Y:
2 4 6 8 10
```

---
