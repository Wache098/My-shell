#include "shell.h"

void loop(void){
    char *line;
    char **args;
    char **commands;
    int status = 1;
    int last_status = 1;
    Alias *alias_list = NULL;

    while(status){
        printf("$ ");

        line = get_line();
        args = parse_line(line);
        commands = parse_line(line);
        status = execute_command(line);

        for(size_t i = 0; commands[i] != NULL; i++ ){
            char **args = parse_line(commands[i]);

            /*Handling of alias built-in commands*/
            if(strcmp(args[0], "alias") == 0){
                if(!args[1]){
                    printf_alias(alias_list, NULL);
                }else{
                    char *name = strtok(args[1], "=");
                    char *value = strtok(NULL, "=");
                    if(value){
                        add_to_aliases(alias_list, name, value);
                    }else{
                        print_alias(alias_list, name);
                    }
                }
                last_status = 0;
            }else{
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
            }
            status = execute_command(args);
            free(args);
            free(commands[i]);
        }

        free(line);
        free(commands);
    }
    free_aliases(alias_list);
}
