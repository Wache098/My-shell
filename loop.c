#include "shell.h"

void loop(void){
    char *line;
    int status = 1;

    while(status){
        printf("$ ");

        line = read_line();
        status = execute_command(line);
        free(line);
    }
}

