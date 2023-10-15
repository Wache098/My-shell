#include "shell.h"


/**
 * main - Simple shell program
 *
 * Return: 0 when successful, -1 on error.
 */

/*void loop(void);*/
int main(void)
{
    char input[MAX_INPUT_SIZE];
    int should_run = 1;
    int len;

    char **args;
    char *line;
    char **commands;
    int last_status = 1;

    /**
     * char *line;
     * char **args;
    */

    while (should_run)
    {
        write(STDOUT_FILENO, "#cisfun$ ", 9);

        if (read(STDIN_FILENO, input, MAX_INPUT_SIZE) <= 0)
        {
            break;
        }

        len = 0;

        /*Execute the function*/
        /*line = get_line();*/ 

        for(size_t i = 0; commands[i] != NULL; i++){
            char **args = parseLine(commands[i]);

            if(strcmp(args[0], "&&") == 0){
                if(last_status == 0){
                    free(args);
                    continue;
                }else{
                    free(args);
                    break;
                }
            }else if(strcmp(args[0], "||") == 0){
                    if(last_status != 0){
                        free(args);
                        continue;
                    }else {
                        free(args);
                        break;
                    }
                }
                last_status = execute_command(args);
                free(args);
                free(commands[i]);
            }



        while (input[len] != '\n' && len < MAX_INPUT_SIZE)
        {
            len++;
        }
        input[len] = '\0';

        if (access(input, F_OK) == 0)
        {
            pid_t child_pid = fork();

            if (child_pid == 0)
            {
                char *args[2];
                args[0] = input;
                args[1] = NULL;

                if (execve(input, args, NULL) == -1)
                {
                    char *error_message = "Error\n";
                    write(STDERR_FILENO, error_message, strlen(error_message));
                    _exit(EXIT_FAILURE);
                }
            }
            else if (child_pid < 0)
            {
                char *error_message = "Fork error\n";
                write(STDERR_FILENO, error_message, strlen(error_message));
            }
            else
            {
                int status;
                waitpid(child_pid, &status, 0);
            }
        }
        else
        {
            char *error_message = "Not found\n";
            write(STDERR_FILENO, error_message, strlen(error_message));
        }
    }

    /**
     * free(line);
     * free(args);
    */

    free(args);
    free(line);
    return (0);
}

