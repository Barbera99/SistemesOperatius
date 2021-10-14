#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int main()
{
    printf("\n Benvinguts a la casa Stark");

    pid_t pid = fork();
    pid_t pid_1;
    
    if (pid > 0)
    {
        pid = getppid();
        printf("\n Hola sóc Rickard Stark casat amb Lyarra Stark amb pid = %d\n", pid); 
        fflush(stdout);
    }
    if (pid == 0)
    {

        printf("\n Hola sóc en Ned fill del matrimoni del Richard i la Lyarra amb pid = %d\n", getpid()); 
        fflush(stdout);
        pid_1 = fork();

        if (pid_1 == 0)
        {
            pid_1 = getpid();
            printf("\n Hola sóc en Robb Stark amb pid = %d, soc un fill del matrimoni de la Catelyn Stark i Ned Stark\n", pid_1); 
            fflush(stdout);
        }
    }
}