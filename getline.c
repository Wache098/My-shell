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
    getline(&line, &len, stdin);

    free(line);


    /*return 0;*/
}
