# Multi Paradigm Statistics Calculator

This project implements a basic statistics calculator in three different programming languages, each demonstrating a different programming paradigm:

- **C**: Procedural Programming
- **OCaml**: Functional Programming
- **Python**: Object-Oriented Programming

## Overview

The program calculates three fundamental statistical measures:
- **Mean**: The average of all integers
- **Median**: The middle value when sorted
- **Mode**: The most frequently occurring value(s)

## Project Structure

```
statistics-calculator/
├── statistics_C.c        # C implementation (Procedural)
├── statistics_ocaml.ml   # OCaml implementation (Functional)
├── statistics_py.py      # Python implementation (Object-Oriented)
└── README.md             # This file
```

## Compilation and Execution

### C (Procedural)

**Compile:**
```bash
gcc statistics_C.c -o statistics_c
```

**Run:**
```bash
./statistics_c
```

### OCaml (Functional)

**Compile:**
```bash
ocamlc statistics_ocaml.ml -o statistics_ocaml
```

**Or run directly:**
```bash
ocaml statistics_ocaml.ml
```

### Python (Object-Oriented)

**Run:**
```bash
python3 statistics_py.py
```

or

```bash
python statistics_py.py
```

## Sample Input/Output

For the input data: `[15, 23, 15, 42, 18, 23, 15, 30, 25, 18]`

All implementations produce:
- **Mean**: 22.40
- **Median**: 20.50
- **Mode(s)**: 15 (appears 3 times)

## Implementation Details

### C (Procedural)
- Uses arrays for data storage
- Manual memory management with `malloc` and `free`
- Separate functions for each calculation
- Simple bubble sort implementation
- Dynamic frequency array allocation based on max value
- Clear, straightforward procedural logic

### OCaml (Functional)
- Immutable data structures (lists)
- Higher-order functions (`fold_left`, `map`, `filter`)
- Pattern matching with `match` expressions
- Recursive functions for frequency counting
- No mutable state - purely functional
- List-based operations throughout

### Python (Object-Oriented)
- `StatisticsCalculator` class encapsulates functionality
- Simple dictionary for frequency counting
- Method-based calculations for each statistic
- Clear encapsulation with class attributes
- Basic, beginner-friendly syntax

## Features

-  Mean calculation (arithmetic average)
-  Median calculation (handles both odd and even list lengths)
-  Mode calculation (handles multiple modes)
-  Clear comments and documentation
-  Identical output across all three languages

## Requirements

- **C**: GCC compiler (or any C compiler)
- **OCaml**: OCaml compiler (version 4.0+)
- **Python**: Python 3.6+

## Acknowledgments

This project demonstrates the differences between procedural, functional, and object-oriented programming paradigms through a practical statistics calculator example. All implementations use simplified, beginner-friendly code while maintaining the core principles of each paradigm.


