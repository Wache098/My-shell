#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

/*void loop(void);*/
char* read_line(void);
char **parse_line(char *line);
int execute_command(char **args);
char *find_executable(char *cmd);
extern char **environ;

#endif /*SHELL_H*/
