# 🎲 Crag – Dice Game

## 📘 Description

- This project implements the **Crag** dice game between a **human player and the computer**.
- The game involves strategy, dice re-rolls, and score-based decision making.
- It focuses on the use of:
  - Functions
  - Loops and conditional logic
  - Structured game flow

---

## 🧠 Game Rules

- Each game consists of **N rounds** (chosen by the user).
- In each round:
  - Both the **player** and the **computer** roll **3 dice**.
  - Dice combinations are evaluated using a **scoring table**.
  - The highest total score after N rounds wins.

---

## 🎯 Scoring Categories

Scores are evaluated **top-down**, and only the **highest applicable category** is used.

| Category         | Description                           | Score | Example Dice     |
|------------------|----------------------------------------|-------|------------------|
| Crag             | Pair + total of 13                     | 50    | 6 6 1            |
| Thirteen         | Total is exactly 13                    | 26    | 3 4 6            |
| Three-Of-A-Kind  | All dice show the same value           | 25    | 4 4 4            |
| Low Straight     | 1-2-3 (in order)                       | 20    | 1 2 3            |
| High Straight    | 4-5-6 (in order)                       | 20    | 4 5 6            |
| Odd Straight     | 1-3-5                                  | 20    | 1 3 5            |
| Even Straight    | 2-4-6                                  | 20    | 2 4 6            |
| Sum              | Any other case → sum of dice values    | n/a   | 2 3 5 = 10       |

---

## 💡 Features

- User-defined number of rounds
- Player can **choose to re-roll** any of the 3 dice once
- Computer will re-roll **only if close to a High Straight (4-5-6)**
- Dice re-roll logic and score evaluation built-in
- Final scores displayed in a clean scoreboard format
- Announces the winner at the end

---

## 🔧 Functions Used

- `roll_a_dice()`  
  - Rolls a die and returns a value between 1–6

- `play_user()`  
  - Handles the player's turn and re-roll choices

- `play_computer()`  
  - Manages the computer's decision to re-roll strategically

- `scoresheet()`  
  - Displays scores for each round

---

## 🖥️ Sample Run (Simplified)

- `Welcome to Crag game!`
- `How many rounds would you like to play? 3`

---

- `Round 1 -- Your Turn:`  
  - `You got → [Dice 1]: 1 [Dice 2]: 2 [Dice 3]: 2`  
  - `Shall I roll for you (Y/N)? Y`  
  - `Which ones do you want to keep? 2 3`  
  - `You got → [Dice 1]: 5 [Dice 2]: 2 [Dice 3]: 2`  
  - `Your score: 9  Total score: 9`

---

- `Round 1 -- My Turn:`  
  - `I rolled → 4 5 1`  
  - `Rolled dice 3 → now 4 5 6`  
  - `My score: 20  Total score: 20`

---

- `Scoresheet:`  
  - `My score: 20`  
  - `Your score: 9`

---

## 🛠️ Constraints

- ❌ No global variables  
- ❌ No arrays or strings  
- ❌ No `goto`, `break`, or `continue`  
- ✅ Only basic C constructs and functions used

---


