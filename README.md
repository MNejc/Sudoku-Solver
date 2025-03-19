
# Sudoku Solver

This is an **old project from 2023**. The program solves Sudoku puzzles using a backtracking algorithm. It supports generating random Sudoku puzzles or reading a puzzle from a file. The program then attempts to solve the puzzle and displays the solution.

## Features

- Solve Sudoku puzzles using backtracking.
- Generate random Sudoku puzzles.
- Read Sudoku puzzles from a file.
- Display the board before and after solving.

## How to Use


1. Compile the code:
   ```bash
   g++ sudoku_solver.cpp -o sudoku_solver
   ```

2. Run the program:
   ```bash
   ./sudoku_solver
   ```

3. When prompted, type `G` to generate a random Sudoku puzzle or puzzle's filename (e.g., `puzzle.txt`).

### Prepare puzzle file

1. Prepare a file with the Sudoku puzzle. Each number in the puzzle should be separated by spaces. Use `0` for empty cells.

   Example board.txt:
   ```
    9 0 4 0 0 0 2 0 6
    0 5 0 0 4 9 0 0 0
    0 0 0 0 0 0 0 0 0
    3 0 0 0 0 2 0 1 0
    0 6 1 0 0 0 0 0 9
    0 0 0 0 8 5 0 0 0
    0 0 0 0 0 0 0 5 0
    7 0 0 2 1 8 0 0 0
    1 9 0 7 0 0 0 0 0
   ```

### Output

The program will print the Sudoku board before solving and the solved board after applying the backtracking algorithm.

