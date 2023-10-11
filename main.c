#include "main.h"

int main( int argc, char **argv) {
    char *username = "jay"; 
    char *hostname = "localhost";
    char cwd[1024];
    char *lineptr;
    // const size_t bufsize = 1024;
    size_t n = 0; 

    /* declaring void variables */
    (void)argc;
    (void)argv;



    while(1){

        // check if in interactive mode 
        if(isatty(0)){
           if(getcwd(cwd, sizeof(cwd)) == NULL){
            perror("getcwd");
            exit(EXIT_FAILURE); 
           }
           else{
            // getcwd(cwd, sizeof(cwd));
            printf("%s@%s:%s ", username, hostname, cwd);
            fflush(stdout);
           }
        }

        // read the input from stdin
        //  printf("%s@%s:%s ", username, hostname, cwd);
        getline(&lineptr, &n, stdin);
        printf("%s\n", lineptr);

        // free up allocated memory
        free(lineptr);
        lineptr = NULL;
    }
    return 0;    
}
