#include <shell.h>

int execute_command(char *command){

    pid_t pid;
    int status;

    char * argv[] = {"/bin/ls", "-l", NULL};

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

