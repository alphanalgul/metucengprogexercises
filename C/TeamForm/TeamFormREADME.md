# Football Team Data Analyzer

This C program reads football team data from a text file, processes the data, and displays several statistics about the teams.

## Features

The program performs the following tasks:

1. **Loads team data from a file**
2. **Displays the loaded data in a table format**
3. **Calculates the average points of all teams**
4. **Counts how many teams played 33 and 34 matches**
5. **Identifies teams with three consecutive wins (`WWW`) in their recent form**

---

# Input File Format

| Played | Points | Team_Name | Form  |
|------|------|-----------|------|
| 34 | 75 | Arsenal | WWWDW |
| 33 | 70 | Liverpool | WLWWW |
| 34 | 65 | Chelsea | LWWDW |
| 33 | 60 | Tottenham | WWWLL |

---

# Sample Output

## League Table

| Team | Played | Points | Form |
|------|------|------|------|
| Arsenal | 34 | 75 | WWWDW |
| Liverpool | 33 | 70 | WLWWW |
| Chelsea | 34 | 65 | LWWDW |
| Tottenham | 33 | 60 | WWWLL |

---

## Statistics

| Average_Points | Teams_Played_33 | Teams_Played_34 |
|---------------|----------------|----------------|
| 67.50 | 2 | 2 |

---

## Teams With Three Consecutive Wins

| Team |
|------|
| Arsenal |
| Liverpool |
| Tottenham |
