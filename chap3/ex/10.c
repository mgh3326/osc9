

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>
int main()
{
pid_t pid,pid1;

	/* fork a child process */
	fork();
	/* fork a child process */
	fork();
	/* fork a child process */
	fork();
    return 0;
}
