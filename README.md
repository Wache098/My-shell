# Simple Shell Project

by [Joseph Musyoki](https://github.com/Musyoki-Wambua?tab=repositories) and [Mary Wachera](https://github.com/Wache098?tab=repositories) for ALX month 2.

## Introduction

This project is a simple Unix-like shell, similar to a basic Unix shell, written in C. The goal is to implement a set of features and functionalities to create a functional command-line interpreter.

## Requirements

- This project adheres to the requirements provided in the project description.
- The code must pass the Betty checks for code style and documentation.
- The code should be compiled using the provided GCC options and work on Ubuntu 20.04 LTS.

## Usage

To use the simple shell, compile the source code and run the executable. You can interact with the shell through the command line, executing various commands and built-in functionalities.

## Features

- A command prompt that waits for user input.
- Basic command execution.
- Error handling for non-existent commands.
- Support for exiting the shell.
- Printing the current environment.
- Handling arguments for built-in functions.

## Built-in Commands

The shell supports the following built-in commands:

- `exit`: Exit the shell.
- `env`: Print the current environment variables.

## Advanced Features

The project includes advanced features such as:

- Custom implementation of the `getline` function.
- Custom parsing of commands (no `strtok` used).
- Handle arguments for the built-in `exit` command.
- Implement the `setenv` and `unsetenv` built-in commands.
- Implement the `cd` built-in command.
- Handle command separators `;`.
- Handle logical operators `&&` and `||`.
- Implement the `alias` built-in command.
- Handle variable replacement (e.g., `$?`, `$$`).
- Handle comments using `#`.
- Support for reading commands from a file.

## Compiling and Running

To compile the shell, use the following GCC command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
