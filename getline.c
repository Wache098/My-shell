#include <stdio.h>
#include <stdlib.h>

/*
stream = read text from the user 
stored in a buffer, size of it will be stored in n
lineptr stores the address of the created buffer 
*/

int main (){
    size_t n;
    // char *buf = malloc(sizeof(char) * n );
    char *buf = NULL;

    printf ("Enter name ");
    getline(&buf, &n, stdin);

    printf("Name is %sBuffer size is %ld\n", buf, n);

    free(buf);

    return 0;
}