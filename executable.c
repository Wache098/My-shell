#include "shell.h"
/**
 * find_executable - Find an executable file in the dir listed in PATH.
 * @cmd: The name of the executable to search for.
 *
 * Return: If a matching executable is found,
 * it returns the full path to the executable;
 * otherwise, it returns NULL.
 */

char *find_executable(char *cmd)
{
char *path_var = getenv("PATH");
char *path = strdup(path_var);
char *dir = strtok(path, ":");
char *executable = NULL;

struct stat st;

while (dir != NULL)
{
executable = malloc(strlen(dir) + strlen(cmd) + 2);
strcpy(executable, dir);
strcat(executable, "/");
strcat(executable, cmd);

<<<<<<< HEAD
if (stat(executable, &st) == 0 && (st.st_mode & S_IXUSR))
{
free(path);
return (executable);
}
free(executable);
dir = strtok(NULL, ":");
}
free(path);
return (NULL);

}
=======
         if (stat(executable, &st) == 0 && (st.st_mode & S_IXUSR)) {
            free(path);
            return(executable);
        }
        dir = strtok(NULL, ":");
        free(executable);
    }
    free(path);
    return NULL;
}
>>>>>>> 929478f3a6b111050a712f61afa21d434339274d
