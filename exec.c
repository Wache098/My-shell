#include <shell.h>

int execute_command(char *command){

    pid_t pid;
    int status;
    char *executable_path;
    char **args = NULL, **envp=NULL;
    /*  char * argv[] = {"/bin/ls", "-l", NULL};*/

    /*Check for the exit Command*/
    if(strcmp(args[0], "exit") == 0){
        exit(EXIT_SUCCESS);
    }

    /*Check for the "env" command*/
    if(strcmp(args[0], "env") == 0){
        char **env = environ;
        while(*env != NULL){
            printf("%s\n", *env);
            env++;
        }
        return 1;
    }

    executable_path = find_executable(args[0]);
    if (executable_path == NULL) {
        fprintf(stderr, "simple_shell: %s: command not found\n", args[0]);
        return 1;
    }

    pid = fork(); /*create child process */

    /*Handle Error*/
    if(pid == -1 )
        return 1;

    /*Child Process*/
    if(pid == 0){
        if(execve(command, NULL, environ) == -1 ){
            perror("ERROR");
        }
        exit(EXIT_FAILURE);
    }else { /*Parent Process*/
        wait(NULL);
        printf("Done with execve\n");
    }

    return 0;
}

