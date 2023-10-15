#include "shell.h"

void loop(void){
    char *line;
    char **args;
    char **commands;
    int status = 1;
    int last_status = 1;

    while(status){
        printf("$ ");

        line = get_line();
        args = parse_line(line);
        commands = parse_line(line);
        status = execute_command(line);

        for(size_t i = 0; commands[i] != NULL; i++ ){
            char **args = parse_line(commands[i]);

            /*&& and || operators*/
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
                }else{
                    free(args);
                    break;
                }
            }
            status = execute_command(args);
            free(args);
            free(commands[i]);
        }

        free(line);
        free(commands);
    }
}
