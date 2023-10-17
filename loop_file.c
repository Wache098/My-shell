#include "shell.h"

void loop_file(FILE *fp){
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char **commands;
    int status = 1;
    size_t i;

    while((nread = getline(&line, &len, fp)) != -1 && status){
        if(line[nread -1] == '\n'){
            line[--nread] = '\0'; /*remove the newline character at end of string*/
        }
        commands= parse_line(line);

        for(i = 0; commands[i] != NULL && status; i++){
            char **args = parse_line(commands[i]);
            status = execute_command(args);
            free(args);
            free(commands[i]);
        }
        free(commands);
    }
    free(line);
}
