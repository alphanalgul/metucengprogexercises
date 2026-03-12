# Instructor Record Manager – Binary Search Tree

## Description

- This project implements an **Instructor Record Manager** using a **Binary Search Tree (BST)** in C.
- The program stores each instructor together with their **academic title**.
- Instructor names are used as the **search key** and are inserted into the tree in **lexicographical order**.
- The program is menu-driven and allows the user to:
  - initialize the tree
  - insert new instructor records
  - search for a specific instructor
  - list instructors whose names begin with a specific character
  - display the tree contents in sorted order

---

## Program Behavior

- The user interacts with the program through a console menu.
- Each instructor record contains:
  - instructor name
  - title
- When a new instructor is inserted:
  - the program compares the name with existing nodes using `strcmp()`
  - if the name is smaller, it goes to the left subtree
  - if the name is greater, it goes to the right subtree
- Because of this structure, an **in-order traversal** prints all instructors in **alphabetical order**.

---

## Menu Options

- `i`  
  - Initializes the tree and makes it empty.

- `n`  
  - Inserts a new instructor record into the BST.
  - User enters:
    - instructor name
    - instructor title

- `t`  
  - Searches for a specific instructor by full name.
  - If found, the program prints the instructor’s title.
  - If not found, it prints:
    - `This instructor does not exist!`

- `s`  
  - Searches for all instructors whose names start with a given character.
  - The program traverses the tree and prints all matching instructors.

- `e`  
  - Exits the program.

---

## Data Structures


---

## Sample Output
Menu:
 i)nitialize
 n)ew element
 t)instructor title
 s)search instructor
 e)xit
Enter command: n

Enter instructors name:JohnSmith
Enter his/her title:Professor
Tree now:

JohnSmith Professor

Menu:
 i)nitialize
 n)ew element
 t)instructor title
 s)search instructor
 e)xit
Enter command: n

Enter instructors name:AliceBrown
Enter his/her title:Lecturer
Tree now:

AliceBrown Lecturer
JohnSmith Professor

Menu:
 i)nitialize
 n)ew element
 t)instructor title
 s)search instructor
 e)xit
Enter command: n

Enter instructors name:MarkWhite
Enter his/her title:AssistantProfessor
Tree now:

AliceBrown Lecturer
JohnSmith Professor
MarkWhite AssistantProfessor

Menu:
 i)nitialize
 n)ew element
 t)instructor title
 s)search instructor
 e)xit
Enter command: t

Enter instructors name:JohnSmith
Professor

Menu:
 i)nitialize
 n)ew element
 t)instructor title
 s)search instructor
 e)xit
Enter command: s

Enter a character:M

MarkWhite AssistantProfessor

Menu:
 i)nitialize
 n)ew element
 t)instructor title
 s)search instructor
 e)xit
Enter command: e
