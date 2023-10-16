#include "shell.h"

char **parse_commands(char *line) {
    size_t bufsize = 64, position = 0;
    char **commands = malloc(bufsize * sizeof(char*));
    char *command_start = line;
    size_t len = strlen(line);
    int in_command = 1;

    if (!commands) {
        fprintf(stderr, "simple_shell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < len; i++) {
        char c = line[i];

        if (c == ';' || i == len-1) {
            size_t command_len = line + i - command_start + (i == len-1);
            char *command = malloc((command_len + 1) * sizeof(char));
            if (!command) {
                fprintf(stderr, "simple_shell: allocation error\n");
                exit(EXIT_FAILURE);
            }
            strncpy(command, command_start, command_len);
            command[command_len - (i == len-1)] = '\0';
            commands[position] = command;
            position++;
            if (position >= bufsize) {
                bufsize += 64;
                commands = realloc(commands, bufsize * sizeof(char*));
                if (!commands) {
                    fprintf(stderr, "simple_shell: allocation error\n");
                    exit(EXIT_FAILURE);
                }
            }
            command_start = line + i + 1;
        }
    }

    commands[position] = NULL;
    return commands;
}
