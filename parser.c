#include "shell.h"

char **parse_line(char *line){
    size_t bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char **commands = malloc(bufsize * sizeof(char*));
    char *command_start = line; 
    char *token_start = NULL;
    size_t len = strlen(line);
    int in_word = 0;
    int in_command = 1;


    if(!tokens){
        fprintf(stderr, "simple_shell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    if (!commands) {
        fprintf(stderr, "simple_shell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    for(size_t i = 0; i < len; i++){
        char c= line[i];

        if(c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\a' || c == ';' || i == len -1){
            if(in_word){
                size_t token_len = line + i -token_start + (i == len -1);
                size_t command_len = line + i -command_start + (i == len -1);
                char *command = malloc((command_len + 1) * sizeof(char));
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
                    if (!command) {
                        fprintf(stderr, "simple_shell: allocation error\n");
                        exit(EXIT_FAILURE);
                    }
                }
                in_word = 0;
            }
        }else if(!in_word){
            /*token_start = &line[i];*/
            token_start = line + 1;
            command_start = line + i + 1;
            in_word = 1;
        }
    }
    tokens[position] = NULL;
    return tokens;
    commands[position] = NULL;
    return commands;
}
