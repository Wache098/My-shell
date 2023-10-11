#include "main.h"

int main() {
    if(isatty(STDIN_FILENO) == 1){
        shell_interactive();
    }
    else{
        shell_non_interactive();
    }
    return 0;
    
}