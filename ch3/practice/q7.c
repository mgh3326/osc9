/**
 * This program forks a separate process using the fork()/exec() system calls.
 *
 * Figure 3.09
 *
 * @author Silberschatz, Galvin, and Gagne
 * Operating System Concepts  - Ninth Edition
 * Copyright John Wiley & Sons - 2013
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid,pid1;

    /* fork a child process */
    pid = fork();

    if (pid < 0)
    { /* error occurred */
        fprintf(stderr, "Fork Failed\n");
        return 1;
    }
    else if (pid == 0)
    {                                  /* child process */
        pid1=getpid();//2603으로 가정
        printf("A : child: pid = %d\n",pid); //A : 0
        printf("B : child: pid = %d\n",pid1); //B : 2603
    }
    else
    { /* parent process */
        /* parent will wait for the child to complete */
        pid1=getpid();//2000으로 가정
        printf("C : child: pid = %d\n",pid); // c : 2603
        printf("D : child: pid = %d\n",pid1); //D : 2000
        wait(NULL);

    }

    return 0;
}
