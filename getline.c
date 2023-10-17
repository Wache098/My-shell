#include "shell.h"

/*
stream = read text from the user 
stored in a buffer, size of it will be stored in n
lineptr stores the address of the created buffer 
*/

char* read_line(void){
    size_t len = 0;
    /*char *buf = malloc(sizeof(char) * n );*/

    char *line = NULL;
    if( getline(&line, &len, stdin)){
    if(feof(stdin)){
        exit(EXIT_SUCCESS); /*Got an EOF*/
    }else {
        free(line); /* avoid memory leaks when getline fails */
        perror("error while reading the line from stdin");
        exit(EXIT_FAILURE);
    }
    }
    return(line);
    /*free(line);*/
    /*return 0;*/
}
