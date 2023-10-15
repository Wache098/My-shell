#include "shell.h"

void loop(void){
    char *line;
    char **args;
    char **commands;
    int status = 1;

    while(status){
        printf("$ ");

        line = read_line();
        args = parse_line(line);
        commands = parse_line(line);
        status = execute_command(line);

        for(size_t i = 0; commands[i] != NULL; i++ ){
            char **args = parse_line(commands[i]);
            status = execute_command(args);
            free(args);
            free(commands[i]);
        }

        free(line);
        free(commands);
    }
}
