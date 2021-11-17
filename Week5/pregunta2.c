#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    signal(SIGINT, SIG_IGN);
    FILE *psFile;
    psFile = fopen("temp.txt", "w");
    fclose(psFile);
    remove("temp.txt");
    while(true) {
    }  
    return 0;
}