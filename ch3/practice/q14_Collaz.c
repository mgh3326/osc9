

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{

    pid_t pid, pid1;
    int num = 0;
    printf("Enter positive integer : ");
    scanf("%d", &num);
    if (num < 0)
    {
        printf("Positive integer was not entered.\tClose the program.\n");
        exit(1);
    }
    /* fork a child process */
    pid = fork();

    if (pid < 0)
    { /* error occurred */
        fprintf(stderr, "Fork Failed\n");
        return 1;
    }
    else if (pid == 0)
    { /* child process */
        while (num > 0)
        {
            if (num == 1)
            {
                printf("%d\n", num);
                break;
            }
            printf("%d, ", num);

            if (num % 2 == 0)
            { //짝수
                num = num / 2;
            }
            else
            { //홀수
                num = 3 * num + 1;
            }
        }
    }
    else
    { /* parent process */
        /* parent will wait for the child to complete */
        wait(NULL);
    }

    return 0;
}