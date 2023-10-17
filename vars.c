#include "shell.h"
#include <stdio.h>

char *replace_vars(char *arg, int last_status){
    char *var;
    /*char *val;*/
    char *new_arg;

    if((var =strstr(arg, "$?")) != NULL){
        asprintf(&new_arg,"%.*s%d%s",(int)(var -arg), arg, last_status, var +2);
        return new_arg;
    }else if((var = strstr(arg, "$$")) != NULL){
        asprintf(&new_arg,"%.*s%d%s", (int)(var-arg), arg, getpid(), var + 2);
        return new_arg;
    }
    return strdup(arg);
}
