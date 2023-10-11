#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main() {
    char *username = "jay"; 
    char *hostname = "localhost";
    char cwd[1024];

    while (1) {
        // check if in interactive mode 
        if (isatty(0)) { 
            //  Display prompt
            getcwd(cwd, sizeof(cwd));
            printf("%s@%s:%s$ ", username, hostname, cwd);
            fflush(stdout); 
        }

        // Read user input
        char input[1024];
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        // Example: Exit the loop if the user enters "exit"
        if (strcmp(input, "exit\n") == 0) {
            break;
        }
    }

    return 0;
}
