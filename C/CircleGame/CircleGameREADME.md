# Circle Game (C)

A console-based board game written in **C** where a player competes against the computer by moving around the edges of a **10×10 board**. Each round both players roll a dice and advance along the perimeter of the board. Traps placed on the board can send players backwards.

The first participant to complete a loop around the board wins.

This project was developed as part of my **Computer Engineering bachelor's coursework** to practice core C programming concepts such as memory management, pointers, and modular program design.

---

## Features

- 10×10 board representation
- Movement restricted to the **perimeter path (36 cells)**
- Random dice rolls for both the player and the computer
- Player-defined trap placement
- Random computer trap generation
- Traps that move players backwards
- Turn-based gameplay
- Dynamic memory allocation
- Input validation for trap placement
- Replayable game loop

---

## Game Rules

1. The board is a **10×10 grid**, but only the **outer perimeter** is used as the movement path.
2. The **player starts at position (0,0)**.
3. The **computer starts at position (9,9)**.
4. Both participants roll a dice each round (**1–6**).
5. Players move clockwise along the board edges.
6. Each side places one trap:
   - The **player selects a trap location**.
   - The **computer trap is generated randomly**.
7. Each trap has a randomly generated **backward movement value (1–5)**.
8. If a player lands on a trap, they move **backwards along the path**.
9. The first player to complete a full loop wins.

---
