# 🎲 Drop Dead – Dice Game

## 📘 Description

- This project implements the **Drop Dead dice game** between a **player and the computer**.
- The game is turn-based and played with 5 dice per turn.
- Key programming concepts used include:
  - Functions
  - Conditional statements
  - Loops
  - Random number generation

---

## 🧠 Game Rules

- Two players: Computer and Human.
- Each round:
  - Player rolls 5 dice.
  - If the roll **contains no 2 or 5**, sum of all dice is added to the score.
  - If the roll **contains any 2 or 5**:
    - Those dice are removed from future rolls.
    - Score for that roll is 0.
  - Player continues rolling with remaining dice until all show 2 or 5 → "Drop Dead".
- Game is played for **N rounds** (user-defined).
- The player with the **highest total score** at the end wins.

---

## 🔧 Functions

- `roll_a_dice()`  
  - Simulates rolling a 6-sided die and returns a value from 1 to 6.

- `play_computer()`  
  - Automates the computer's full turn based on the rules.

- `play_user()`  
  - Automates the user's full turn with console outputs for results.

- `scoresheet()`  
  - Displays the accumulated scores of both players after each round.

---

## 💡 Features

- Allows the user to choose the number of rounds
- Randomized dice rolls for fairness
- Detects and removes dice with 2 or 5 automatically
- Tracks total scores across rounds
- Declares a winner at the end

---

## 🖥️ Sample Run (Simplified)

- `Welcome to the Drop Dead game!`
- `How many rounds would you like to play? 2`

---

- `Round 1 -- My Turn:`  
  - `I got → [Dice 1]: 1 [Dice 2]: 2 [Dice 3]: 2 [Dice 4]: 4 [Dice 5]: 5`  
  - `My score: 0 Total score: 0`  
  - `Dice 2 Dice 3 Dice 5 are excluded!`  
  - `... continues rolling until drop dead`

---

- `Round 1 -- Your Turn:`  
  - `Are you ready to play!`  
  - `I rolled them for you and you got → [Dice 1]: 1 [Dice 2]: 6 [Dice 3]: 6 [Dice 4]: 4 [Dice 5]: 4`  
  - `Your score: 21 Total score: 21`  
  - `... continues rolling until drop dead`

---

- `Scoresheet after Round 1:`  
  - `My Score: 29`  
  - `Your Score: 21`

---

## 🛠️ Technical Constraints

- ❌ No global variables  
- ❌ No arrays or strings  
- ❌ No `goto` statements  
- ✅ Use functions and basic C control structures (`if`, `while`, etc.)

---


