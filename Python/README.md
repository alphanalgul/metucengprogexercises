# Python Programming Exercises

This folder contains Python programming exercises completed as part of my METU NCC Computer Engineering programming practice for CNG 111 Introduction to Computer Engineering Concepts and CNG 465 Introduction to Bioinformatics. The exercises mainly focus on Python fundamentals, string processing, regular expressions, mathematical helper functions, and basic bioinformatics operations such as DNA transcription, translation, reverse complements, reading frames, and sequence alignment.

## Contents

| File                                                               | Description                                                                                                                     |
| ------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------- |
| [`string.py`](./string.py)                                         | Finds and prints the middle three characters of a string.                                                                       |
| [`remove_spaces.py`](./remove_spaces.py)                           | Removes spaces from a string manually using a loop.                                                                             |
| [`reverse.py`](./reverse.py)                                       | Reverses a DNA sequence string.                                                                                                 |
| [`complement.py`](./complement.py)                                 | Generates the complementary DNA sequence using base-pair rules.                                                                 |
| [`reverse-complement.py`](./reverse-complement.py)                 | Generates the reverse complement of a DNA sequence.                                                                             |
| [`transcription.py`](./transcription.py)                           | Converts a DNA sequence into an RNA sequence by replacing `T` with `U`.                                                         |
| [`translation.py`](./translation.py)                               | Translates an RNA/DNA sequence into amino acids starting from the start codon `AUG`.                                            |
| [`ReadingFrames.py`](./ReadingFrames.py)                           | Finds the six possible reading frames of a DNA sequence.                                                                        |
| [`biopythonlibrary.py`](./biopythonlibrary.py)                     | Demonstrates basic Biopython `Seq` operations such as complement, reverse complement, transcription, and translation.           |
| [`Needleman-Wunsch-Alignment.py`](./Needleman-Wunsch-Alignment.py) | Implements a sequence alignment exercise using a scoring matrix, gap score, dynamic programming table, and traceback.           |
| [`regular-expressions.py`](./regular-expressions.py)               | Demonstrates Python regular expression operations such as `findall`, `search`, `sub`, `split`, `match`, and character counting. |
| [`lcm-gcd.py`](./lcm-gcd.py)                                       | Calculates the least common multiple and greatest common divisor of two numbers.                                                |

## Topics Covered

* Python variables and strings
* Loops and conditionals
* Functions
* String slicing
* String replacement
* Input handling
* Mathematical helper functions
* Greatest common divisor and least common multiple
* Regular expressions with the `re` module
* DNA complement generation
* DNA reverse complement generation
* DNA to RNA transcription
* Codon-based translation
* Reading frame generation
* Basic Biopython usage
* Dynamic programming for sequence alignment

## Requirements

Most scripts only require standard Python.

For the Biopython-related examples, install the required libraries:

```bash
pip install biopython numpy
```

The following files use external libraries:

| File                            | Required Libraries   |
| ------------------------------- | -------------------- |
| `biopythonlibrary.py`           | `biopython`          |
| `Needleman-Wunsch-Alignment.py` | `numpy`, `biopython` |

## How to Run

Run any file directly with Python:

```bash
python reverse.py
```

Example:

```bash
python transcription.py
```

The script prints the original DNA sequence and the transcribed RNA sequence.

For the alignment exercise:

```bash
python Needleman-Wunsch-Alignment.py
```

For the GCD/LCM exercise:

```bash
python lcm-gcd.py
```

Then enter two numbers when prompted.

## Example Exercises

### Reverse a DNA Sequence

```python
sequence = "ataacgtggatgcta"
```

Output:

```text
ATAACGTGGATGCTA
ATCGTAGGTGCAATA
```

### DNA Transcription

DNA:

```text
ATAACGTGGATGCTA
```

RNA:

```text
AUAACGUGGAUGCUA
```

### DNA Complement

DNA base-pair rules used:

| DNA Base | Complement |
| -------- | ---------- |
| A        | T          |
| T        | A          |
| G        | C          |
| C        | G          |

### Translation

The translation script searches for the start codon `AUG`, groups the sequence into codons, converts codons into amino acids, and stops when it reaches a stop codon.

### Regular Expressions

The regex exercise demonstrates examples such as:

```python
re.findall("T", sequence)
re.search("is", text)
re.sub("e", "a", text)
re.split(" ", text)
re.match(r"^A.*e$", word)
```

### GCD and LCM

The math utility calculates:

```text
greatest common divisor
least common multiple
```

for two user-provided integers.

## Notes

These scripts are written as individual practice files, not as one large Python package. Most files use hardcoded example sequences and print results directly. They are best tested by running each file separately from the command line.

Some filenames are intentionally descriptive, but for larger projects it would be better to use consistent lowercase names with underscores, such as:

```text
needleman_wunsch_alignment.py
reverse_complement.py
regular_expressions.py
lcm_gcd.py
```
