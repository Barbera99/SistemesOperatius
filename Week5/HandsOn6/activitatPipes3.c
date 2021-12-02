#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int fd[2];
    char s[100];
    char *p1[] = {"ls", NULL};
    char *p2[] = {"wc", "-l", NULL};

    if (pipe(fd) < 0)
    {
        perror("Error de creació del pipe fd[]");
        exit(-1);
    }

    int pid;
    int pid2;

    switch (pid = fork())
    {
    case -1:
        perror("Error fork()");
        exit(-2);
        break;

    case 0: //Fill 1 ls
        dup2(fd[1], 1);
        close(fd[0]);
        close(fd[1]);
        execvp(p1[0], p1);

    default: //Pare
        pid2 = fork();
        if (pid2 == 0)
        { //Fill 2 wc -l
            dup2(fd[0], 0);
            close(fd[1]);
            close(fd[0]);
            execvp(p2[0], p2);
        }
        else
        { //pare

            close(fd[0]);        // És redundant, no fa falta tancar 
            close(fd[1]);        // Hem de tancar l'escriptura (entrada) per a que acabi el procés del fill.
            waitpid(pid, 0, 0);  // Esperem al ls
            waitpid(pid2, 0, 0); // Esperem al wc
            exit(0);
        }
    }
}