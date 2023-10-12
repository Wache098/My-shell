#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

void shell_interactive();
void shell_non_interactive();
ssize_t read_input(char *input, size_t size);
int check_input(char *input);
void execute_command(char *input);

#endif /*MAIN_H*/
