# C Sudoku Solver

A lightweight, efficient command-line Sudoku solver written in C. This program uses a **recursive backtracking algorithm** to solve any valid 9x9 Sudoku puzzle.

## Features
* **Fast Execution**: Utilizes early returns and optimized constraint checking (row, column, and 3x3 subgrid).
* **Robust Input Handling**: Safely parses user input, ignoring extra spaces, tabs, or empty lines.
* **In-Place Solving**: Solves the puzzle by mutating the grid directly via pointers/arrays.

## How It Works
The solver uses a classic brute-force backtracking approach:
1. It scans the 9x9 grid for an empty cell (represented by a `0`).
2. It attempts to place a digit from `1` to `9` in that cell.
3. Before placing a digit, it checks if the move is legal (no duplicates in the current row, column, or 3x3 subgrid).
4. If legal, it recursively attempts to solve the rest of the board.
5. If it reaches a dead end, it backtracks (resets the cell to `0`) and tries the next digit.

## Getting Started

### Prerequisites
You need a C compiler (like `gcc`) installed on your system.

### Compilation
Clone the repository and compile the code using `gcc`:

```bash
gcc Sudoku.c -o Sudoku
