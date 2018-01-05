

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>
int value = 5; //전역변수네
int main()
{
	pid_t pid, pid1;

	/* fork a child process */
	pid = fork(); //부모는 자식의 pid를, 자식은 0을 리턴 받게 됩니다.

	if (pid < 0)
	{ /* error occurred */
		fprintf(stderr, "Fork Failed\n");
		exit(-1);
	}
	else if (pid == 0)
	{ /* child process */
		value += 15;
		printf("CHILD: value = (%d)\n", value);

		return 0;
	}
	else
	{ /* parent process */
		/* parent will wait for the child to complete */
		wait(NULL);

		printf("PARENT: value = (%d)\n", value);
		//부모와 차일드는 전역변수가 따로 관리된다.
		//exit(0);
	}
	return 0;
}
