# Brainfuck Compiler

This repository contains a minified Brainfuck compiler written in C. The compiler reads Brainfuck source code from a file and generates a functionally equivalent C program. This is meant as a toy project rather than a useful program.

## Getting Started

### Prerequisites

- GCC (GNU Compiler Collection) installed on your system.

### Usage

  Paste (or type) your bf code in `c.bf`.

  Compile the compiler:
  
  ```sh
  gcc main.c -o main
  ```

  Run the executable to generate the C program:

  ```sh
  ./main.exe
  ```

  Compile the generated C program:

  ```sh
  gcc o.c -o o
  ```

  Run the C executable:

  ```sh
  ./o.exe
  ```
