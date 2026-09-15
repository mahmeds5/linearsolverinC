# Gaussian Elimination Matrix Solver

A C program that solves a system of linear equations using Gaussian elimination with back-substitution.

## Features

- Accepts any number of equations/unknowns (up to 10, adjustable via `MAX`)
- Builds an augmented matrix from user input
- Reduces the matrix to row echelon form
- Solves for all variables using back-substitution
- Displays the matrix before and after elimination, plus the final solutions

## How It Works

1. Prompts for the number of equations (`n`)
2. Collects coefficients and constants row by row into an augmented matrix
3. Performs Gaussian elimination (row-by-row, column-by-column) to zero out values below the diagonal
4. Uses back-substitution, starting from the last equation, to solve for each variable

## Requirements

- A C compiler (e.g. `gcc`)

## How to Run

```bash
gcc matrixSolver.c -o matrixSolver
./matrixSolver
```

## Known Limitations

- No handling for a zero pivot (division by zero if one occurs) — pivoting is not yet implemented
- Max system size is fixed at compile time via `#define MAX 10`

## Notes

Built as a project to learn C fundamentals — arrays, nested loops, and translating a math algorithm (Gaussian elimination) into actual code.
