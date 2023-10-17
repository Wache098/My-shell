#include "shell.h"

void loop(void){
    char *line;
    char **args;
    char **commands;
    int status = 1;
    int last_status = 1;
    Alias *alias_list = NULL;
    size_t i, j;

    while(status){
        printf("$ ");

        line = get_line();
        args = parse_line(line); /* tokenize line */
        commands = parse_commands(line);

        status = execute_command(args);
        
        for(i = 0; commands[i] != NULL; i++ ){
            char **args = parse_line(commands[i]);

            /*Variable replacement in each arg*/
            
            for(j = 0; args[i] != NULL; j++ ){
                char *new_arg = replace_vars(args[j], last_status);
                free(args[j]);
                args[j] = new_arg;
            }

            /*Handling of alias built-in commands*/
            if(strcmp(args[0], "alias") == 0){
                if(!args[1]){
                    print_alias(alias_list, NULL);
                }else{
                    char *name = strtok(args[1], "=");
                    char *value = strtok(NULL, "=");
                    if(value){
                        add_alias(&alias_list, name, value);
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
            /*status = execute_command(args);*/
            last_status = execute_command(args);
            free(args);
            free(commands[i]);
        }

        free(line);
        free(commands);
    }
    free_aliases(alias_list);
}
