#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_ENV_VARS 100

extern char **environ;

/**
 * set_env_var - Set an environment variable.
 * @key: The key of the environment variable.
 * @value: The value to set.
 */
void set_env_var(char *key, char *value) {
    int i;

    for (i = 0; i < MAX_ENV_VARS && environ[i] != NULL; i++) {
        if (strstr(environ[i], key) == environ[i]) {
            snprintf(environ[i], strlen(key) + strlen(value) + 2, "%s=%s", key, value);
            return;
        }
    }

    if (i < MAX_ENV_VARS) {
        environ[i] = malloc(strlen(key) + strlen(value) + 2);
        if (environ[i] != NULL) {
            snprintf(environ[i], strlen(key) + strlen(value) + 2, "%s=%s", key, value);
            environ[i + 1] = NULL;
        }
    }
}

/**
 * get_env_var - Get the value of an environment variable.
 * @key: The key of the environment variable.
 * Return: The value of the environment variable or NULL if not found.
 */
char *get_env_var(char *key) {
    int i;

    for (i = 0; i < MAX_ENV_VARS && environ[i] != NULL; i++) {
        if (strstr(environ[i], key) == environ[i]) {
            char *value = strchr(environ[i], '=');
            if (value != NULL)
                return value + 1;
        }
    }

    return NULL;
}

/**
 * unset_env_var - Unset an environment variable.
 * @key: The key of the environment variable to unset.
 */
void unset_env_var(char *key) {
    int i, j;

    for (i = 0; i < MAX_ENV_VARS && environ[i] != NULL; i++) {
        if (strstr(environ[i], key) == environ[i]) {
            free(environ[i]);
            for (j = i; j < MAX_ENV_VARS && environ[j] != NULL; j++) {
                environ[j] = environ[j + 1];
            }
        }
    }
}

int main() {
    environ = malloc((MAX_ENV_VARS + 1) * sizeof(char *));
    if (environ == NULL)
        return 1;
    memset(environ, 0, (MAX_ENV_VARS + 1) * sizeof(char *));

    set_env_var("SHELL", "/bin/sh");
    set_env_var("USER", "johndoe");
    set_env_var("PATH", "/usr/bin:/bin");

    char *user = get_env_var("USER");
    char *path = get_env_var("PATH");

    if (user != NULL)
        printf("USER=%s\n", user);

    if (path != NULL)
        printf("PATH=%s\n", path);

    unset_env_var("USER");
    char *unsetUser = get_env_var("USER");
    if (unsetUser == NULL)
        printf("USER is unset\n");

    free(environ);
    return 0;
}

