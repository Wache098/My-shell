#include "shell.h"

void loop(void){
    char *line;
    char **args;
    int status = 1;

    while(status){
        printf("$ ");

        line = read_line();
        args = parse_line(line);
        status = execute_command(line);

        free(line);
        free(args);
    }
}
