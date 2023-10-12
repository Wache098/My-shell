#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main (){

    pid_t pid;

    char * argv[] = {"/bin/ls", "-l", NULL};

    pid = fork(); //create child process 

    // Handle Error
    if(pid == -1 )
        return 1;

    // Child Process
    if(pid == 0){
        int val = execve(argv[0], argv, NULL); //execve doesn't return anything
        if(val == -1 ){
            perror("Error");
        }
    }else { //Parent Process
        wait(NULL);
        printf("Done with execve\n");
    }

    return 0;
}