#include "shell.h"

char **parse_line(char *line) {
    size_t bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token, *saveptr;
    char *comment_pos;

    if (!tokens) {
        fprintf(stderr, "simple_shell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    /*Handle comments: ignore everything after #*/
    comment_pos = strchr(line, '#');
    if (comment_pos) {
        *comment_pos = '\0';
    }

    token = strtok_r(line, " \t\r\n\a", &saveptr);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "simple_shell: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

         token = strtok_r(NULL, " \t\r\n\a", &saveptr);

        
    }
    tokens[position] = NULL;
    /**
     * int i;  
     * for (i = 0; tokens[i] != NULL; i++) {
        printf("token[%d]: %s\n", i, tokens[i]);
    }
    return tokens;
    */  
    return tokens;
}
