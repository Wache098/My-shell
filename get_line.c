#include "shell.h"

#define BUFFER_SIZE 1024

char *get_line(void){
    static char buffer[BUFFER_SIZE];
    static char *ptr = buffer;
    static int chars_left = 0;
    char *line = NULL;
    size_t len = 0;

    char *newline = memchr(ptr, '\n', chars_left);

    

    while(1){
        if(chars_left <= 0 ) {
            chars_left = read(STDIN_FILENO, buffer, sizeof(buffer));
            ptr = buffer;
            if(chars_left <= 0){
                if(len == 0){
                    return NULL; /*EOF*/
                }
                break; /*Return the last line*/
            }
        }
        /*Allocate memory for the line*/
        len += chars_left;
        line = realloc(line, len + 1);
        if(!line){
            perror("get_line");
            exit(EXIT_FAILURE);
        }

        /*Find the end of such line*/
        if(newline){
            size_t line_len = newline -ptr;
            strncpy(line + len - chars_left, ptr, line_len);
            line[len - chars_left + line_len] = '\0';
            ptr = newline + 1;
            chars_left -= line_len + 1;
            return line;
        }
        
        /*Copy buffer to the line and continue*/
        strncpy(line + len -chars_left, ptr, chars_left);
        chars_left = 0;
    }
    line[len] = '\0';
    return line;
}
