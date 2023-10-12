#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>


int main() {
    int a =9; 
    int b = 6;

    // pid_t pid;
    pid_t ppid;

    int difference = a-b;
    printf("Difference of a and b is %d\n", difference);

    ppid = getppid();
    printf("PPID is %u\n", ppid);

    return 0; 
}
