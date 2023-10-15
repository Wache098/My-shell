#include "shell.h"

char *find_executable(char *cmd){
    char *path_var = getenv("PATH");
    char *path = strdup(path_var);
    char *dir = strtok(path, ":");
    char *executable = NULL;

    struct stat st;

    while(dir!= NULL){
        executable = malloc(strlen(dir) + strlen(cmd) +2);
        strcpy(executable, dir);
        strcat(executable,"/");
        strcat(executable, cmd );

         if (stat(executable, &st) == 0 && (st.st_mode & S_IXUSR)) {
            free(path);
            return(executable);
        }
        free(executable);
        dir = strtok(NULL, ":");
    }
    free(path);
    return NULL;

}
