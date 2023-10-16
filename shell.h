#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_INPUT_SIZE 1024

/*Alias Structure*/
typedef struct Alias
{
    /* data */
    char *name;
    char*value;
    struct Alias *next;
} Alias;


void loop(void);
void loop_file(FILE *fp);
char* read_line(void);
char **parse_line(char *line);
char **parse_commands(char *line);
char *get_line(void);
int execute_command(char **args);
char *find_executable(char *cmd);
void add_alias(Alias **alias_list, const char *name, const char *value);
void print_alias(const Alias *alias_list, const char *name);
void free_aliases(Alias *alias_list);
char *replace_vars(char *arg, int last_status);

extern char **environ;

#endif /*SHELL_H*/
