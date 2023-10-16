#include "shell.h"

int main(int argc, char **argv){
    (void)argc;
    (void)argv;

    if(argc > 1 ){
        FILE *fp = fopen(argv[1], "r");
        if(!fp){
            fprintf(stderr, "simple_shell: cannot open file %s\n", argv[1]);
            return EXIT_FAILURE;
        }
        loop_file(fp);
        fclose(fp);
    }else{
        loop();
    }
    return EXIT_SUCCESS;
}
