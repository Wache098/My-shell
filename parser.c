#include "shell.h"
/*Split line into arguments using strtok()*/

char **parse_line(char *line){
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if(!token){
        perror("ERROR");
        /*return(NULL);*/
        exit(EXIT_FAILURE);
    }

    token = strtok(line, "\t\r\n\a");
    while( token != NULL){
        tokens[position] = token;
        position++;

        if(position >= bufsize){
            bufsize += 64; 
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if(!tokens){
                perror("ERROR");
                exit(EXIT_FAILURE);
                /*return (NULL);*/
            }
        }
        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[position] = NULL;
    return tokens;
}
