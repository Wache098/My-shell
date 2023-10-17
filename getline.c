#include "shell.h"

/*
stream = read text from the user 
stored in a buffer, size of it will be stored in n
lineptr stores the address of the created buffer 
*/

char* read_line(void){
    size_t len = 0; /*will change according to input*/
    /*char *buf = malloc(sizeof(char) * n );*/

    char *line = NULL;

    if (isatty(STDIN_FILENO) == 1)
		write(1, "$ ", 2); /*Display prompt Character*/

    if( getline(&line, &len, stdin) <= 0){
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "\n", 1);/*Add a new line after input*/
            free(line);
		/*exit(NULL, line);*/
        return NULL;
	}
    return(line);
    /*free(line);*/
    /*return 0;*/
}
