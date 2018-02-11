

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>
int value = 5;			   //전역변수네
int memo[50];			   //이걸 크게 해야 좋은걸까?
long long fibonacci(int n) //메모이제이션
{						   //메모이제이션을 추가한 방법의 시간 복잡도는 O(N)입니다.
	if (n <= 1)
	{
		return n;
	}
	else if (memo[n] != 0)
	{
		return memo[n];
	}
	else
	{
		return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
	/*if (n == 0)//
이 방법은 재귀 호출을 이용한 방법입니다. 시간 복잡도는 대략 O(2N) 정도가 나오게 됩니다. 
		return 0;
	else if (n == 1)
		return 1;
	else
	{
		long long a = fibonacci(n - 1) + fibonacci(n - 2);
		return a;
	}*/
}
int main()
{
	int num = 0;
	pid_t pid, pid1;
			printf("Input Number of progression please : ");

	scanf("%d", &num);
	if(num<0)
	{
		printf("Error : Enter positive number.\n");
		exit(0);
	}
	/* fork a child process */
	pid = fork(); //부모는 자식의 pid를, 자식은 0을 리턴 받게 됩니다.

	if (pid < 0)
	{ /* error occurred */
		fprintf(stderr, "Fork Failed\n");
		exit(-1);
	}
	else if (pid == 0)
	{ /* child process */
		printf("fibonacci(%d) : (%lld)\n", num, fibonacci(num));

		return 0;
	}
	else
	{ /* parent process */
		/* parent will wait for the child to complete */
		wait(NULL);

		printf("PARENT wait complete\n");
		//부모와 차일드는 전역변수가 따로 관리된다.
		//exit(0);
	}
	return 0;
}
