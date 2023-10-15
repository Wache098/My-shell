#include "shell.h"

void loop(void){
    char *line;
    int status = 1;

    while(status){
        write(STDOUT_FILENO, "#cisfun$ ", 9);

        line = read_line();
        status = execute_command(line);
        free(line);
    }
}

