#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

ssize_t read_input(char *input, size_t size);
int check_input(char *input);
void execute_command(char *input);

/**
 * main - Entry point for the simple shell program
 *
 * Return: 0 on success, -1 on error
 */
int main(void)
{
char input[MAX_INPUT_SIZE];
int should_run = 1;

while (should_run)
{
write(STDOUT_FILENO, "#cisfun$ ", 9);
if (read_input(input, MAX_INPUT_SIZE) == -1)
{
break;
}
if (check_input(input) == 0)
{
execute_command(input);
}
}
return (0);
}

/**
 * read_input - Read input from standard input
 * @input: Buffer to store the input
 * @size: Maximum size of the input
 *
 * Return: Number of bytes read, or -1 on error
 */
ssize_t read_input(char *input, size_t size)
{
ssize_t bytes_read;


bytes_read = read(STDIN_FILENO, input, size);
if (bytes_read <= 0)
{
return (-1);
}
if (input[bytes_read - 1] == '\n')
{
input[bytes_read - 1] = '\0';
}
else
{
input[bytes_read] = '\0';
}
return (bytes_read);
}

/**
 * check_input - Check if the given input corresponds to an existing file
 * @input: User-provided input
 *
 * Return: 0 if the input corresponds to an existing file, 1 otherwise
 */
int check_input(char *input)

{
char *error_message;

if (access(input, F_OK) == 0)
return (0);
error_message = "Not found\n";
write(STDERR_FILENO, error_message, strlen(error_message));
return (1);
}

/**
 * execute_command - Execute a command
 * @input: User-provided input (command)
 */
void execute_command(char *input)
{
pid_t child_pid = fork();

if (child_pid == 0)
{
char *args[2];
args[0] = input;
args[1] = NULL;
if (execve(input, args, NULL) == -1)
{
char *error_message = "Error\n";
write(STDERR_FILENO, error_message, strlen(error_message));
_exit(EXIT_FAILURE);
}
}
else if (child_pid < 0)
{
char *error_message = "Fork error\n";
write(STDERR_FILENO, error_message, strlen(error_message));
}
else
{
int status;
waitpid(child_pid, &status, 0);
}
}

