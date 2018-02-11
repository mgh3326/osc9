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
#define SIZE 5

int nums[SIZE] = {0, 1, 2, 3, 4};
int main()
{
    int i;
    pid_t pid;

    /* fork a child process */
    pid = fork();

    if (pid == 0)
    { /* child process */
        for (i = 0; i < SIZE; i++)
        {
            nums[i] *= -i;
            printf("CHILD : %d ", nums[i]); //LINE X!!!
        }
    }
    else
    { /* parent process */
        /* parent will wait for the child to complete */
        wait(NULL);
        for (i = 0; i  < SIZE; i++)
            printf("PARENT : %d ", nums[i]); //LINE Y!!!
    }
    return 0;
}
