#include "shell.h"

char **parse_line(char *line){
    size_t bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token_start = NULL;
    size_t len = strlen(line);
    int in_word = 0;


    if(!tokens){
        fprintf(stderr, "simple_shell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    for(size_t i = 0; i < len; i++){
        char c= line[i];

        if(c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\a' || i == len -1){
            if(in_word){
                size_t token_len = line + i -token_start + (i == len -1);
                token_start[token_len - ( i == len -1)] = '\0';
                tokens[position] = strdup(token_start);
                position++;
                if(position >= bufsize){
                    bufsize += 64;
                    tokens = realloc(tokens, bufsize * sizeof(char*));
                    if(!tokens){
                        fprintf(stderr, "simple_shell: allocation error\n");
                        exit(EXIT_FAILURE);
                    }
                }
                in_word = 0;
            }
        }else if(!in_word){
            /*token_start = &line[i];*/
            token_start = line + 1;
            in_word = 1;
        }
    }
    tokens[position] = NULL;
    return tokens;
}
