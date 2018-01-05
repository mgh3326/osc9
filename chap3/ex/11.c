

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>
int main()
{
pid_t pid,pid1;

	/* fork a child process */
	pid = fork();//부모는 자식의 pid를, 자식은 0을 리턴 받게 됩니다. 

	if (pid < 0) { /* error occurred */
		fprintf(stderr, "Fork Failed\n");
		exit(-1);
	}
	else if (pid == 0) { /* child process */
        pid1=getpid();//현재 pid를 리턴받게 됩니다.
		printf("child: pid=(%d)\n",pid);
        printf("child: pid1=(%d)\n",pid1);
	}
	else { /* parent process */
		/* parent will wait for the child to complete */
		pid1=getpid();//현재 pid를 리턴받게 됩니다.
		printf("parent: pid=(%d)\n",pid);
        printf("parent: pid1=(%d)\n",pid1);
		wait(NULL);
		
		printf("Child Complete\n");
		//exit(0);
	}
    return 0;
}
