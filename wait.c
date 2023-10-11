#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void) {
    pid_t pid, ppid;
    pid = getpid();
    ppid = getppid();

    printf("Before fork, ppid = %u\n", ppid);

    pid = fork(); 
    if (pid == -1) {
        perror("Unsuccessful\n");
        return 1;
    }

    if (pid == 0) {
        // Execute code when in the child process. Return 0
        printf("Child process, pid = %u\n", pid);
    } else {
        // Execute code in Parent process. Return 0 >  1
        wait(NULL);
        sleep(40); 
        printf("Parent process, ppid =  %u\n", ppid);
    }
    return 0;
}
