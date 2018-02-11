

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main()
{
    pid_t pid, pid1;

    /* fork a child process */
    pid = fork();

    if (pid < 0)
    { /* error occurred */
        fprintf(stderr, "Fork Failed\n");
        return 1;
    }
    else if (pid == 0)
    { /* child process */
        printf("Child Start\n");
        printf("Child End\n");
        exit(1);
    }
    else
    { /* parent process */
        /* parent will wait for the child to complete */
        printf("Preant Start\n");
                sleep(20);

        printf("Preant End\n");
    }

    return 0;
}
