#include "shell.h"

int execute_command(char **args){

    /**
     * execute_command - create a new process
     * @args: array of strings that contains the command and its flags
     *
     * Return: 1 if success, 0 otherwise.
    */

    pid_t pid;
    int status;
    char *executable_path;
    /*char **args = NULL, **envp=NULL;*/
    static char *last_dir = NULL;
    /*  char * argv[] = {"/bin/ls", "-l", NULL};*/

    /*Check for the exit Command*/
    if(strcmp(args[0], "exit") == 0){
        if(args[1]){
            int exit_status = atoi(args[1]);
            exit(exit_status);
        }else{
            exit(EXIT_SUCCESS);
        }
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

    /*Check for the "cd" command*/
    if(strcmp(args[0], "cd") == 0){
        char *dir = args[1];
        char *home = getenv("HOME");
        char cwd[1024];

        if(!dir || (dir && strcmp(dir, "~")) == 0){
            dir = home;
        }else if(dir && strcmp(dir, "-") == 0){
            if(last_dir){
                /*free(cwd);*/
                dir = last_dir;
            }else{
                fprintf(stderr, "simple_shell: cd: OLDPWD not set\n");
                return 1;
            }
        }
        if(chdir(dir) != 0){
            perror("ERROR");
            return 1;
        }
        free(last_dir);
        getcwd(cwd, sizeof(cwd));
        /*last_dir = malloc(sizeof(char)*strlen(cwd)+1);*/
        last_dir = strdup(cwd);
        setenv("PWD", cwd, 1);
        return 1;
    }

    /*Check for the "setenv" command*/

    if(strcmp(args[0], "setenv") == 0){
        if(args[1] && args[2]){
            if(setenv(args[1], args[2], 1) != 0){
                  fprintf(stderr, "simple_shell: setenv: failure\n");
            }
            return -1;
        }else {
             fprintf(stderr, "simple_shell: setenv: missing arguments\n");
             return -1;
        }
    }

    /*Check for "unsetenv" command*/

    if(strcmp(args[0], "unsetenv") == 0){
        if(args[1]){
            if(unsetenv(args[1]) != 0){
                fprintf(stderr, "simple_shell: unsetenv: failure\n");
            }
            return 1;
        }else {
            fprintf(stderr, "simple_shell: unsetenv: missing argument\n");
            return 1;
        }
    }

    executable_path = find_executable(args[0]);
    if (executable_path == NULL) {
        fprintf(stderr, "ERROR: %s: command not found\n", args[0]);
        return 1;
    }
    

    pid = fork(); /*create child process */

    /*Handle Error*/
    if(pid == -1 ){
         perror("ERROR");
        return 1;
    }
        
    /*Child Process*/
    if(pid == 0){
        if(execve(executable_path, args, environ) == -1 ){
            perror("ERROR");
        }
        exit(EXIT_FAILURE);
    }else { /*Parent Process*/
        do{
            waitpid(pid, &status, WUNTRACED);
        }while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    free(executable_path);
    return 1;
}
