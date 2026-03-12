# Flight Booking & Investment Simulator

## Description

- This project implements a **Flight Booking Simulation System** in **C**.
- The program simulates a simple airline booking process with **economy** and **business class** seats.
- Users can repeatedly make bookings until all seats are filled or they choose to stop.
- After bookings are completed, the program calculates:
  - total earnings from seat sales
  - projected investment value using **25% annual return**
- Based on the return on investment, the program **recommends future flight planning decisions**.

---

## Program Behavior

1. The user first enters an **even number of seats**.
2. Seats are divided equally:
   - Half → **Economy Class**
   - Half → **Business Class**
3. The user is repeatedly asked if they want to make a booking.
4. When booking:
   - `1` → Economy seat
   - `2` → Business seat
5. If a class becomes full:
   - The program asks the user to try the other class.
6. When bookings are finished:
   - The program calculates **total revenue**.
7. The user then enters the **number of years to invest the money**.
8. The program calculates the **future value of the investment** using recursion.

---

## Seat Pricing

| Class | Price |
|------|------|
| Economy | \$100 |
| Business | \$200 |

---

## Data Representation

The program uses an **array** to represent seat bookings.

```c
int array[n];
```

---
## Features

- **Reads internship records from a file**
- **Separate economy and business seat allocation**
- **Automatic detection when a class becomes full**
- **Revenue calculation**
- **Recommendation system based on financial performance**
- ****

---



```c
int array[n];
