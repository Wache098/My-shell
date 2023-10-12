#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


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
        // sleep(40); //make the process sleep of this amount of seconds
        printf("After fork I become the child, pid = %u\n", pid);
    } else {
        // Execute code in Parent process. Return 0 >  1
        sleep(40); 
        printf("I am the parent, either way, ppid =  %u\n", ppid);
    }
    return 0;
}
