

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#define MIN_PID 300
#define MAX_PID 5000
int pid_array[MAX_PID] = {
    0,
};

int allocate_map(void); //pid를 나타내기 위한 자료ㅗ구조를 생성하고 초기화 한다.
//  반환값이 -1이면 실패, 값이 1이면 성공을 나타낸다.
int allocate_pid(void); //pid를 할당하고 반환한다.
//반환값 -1은 모든 pid가 사용 중이기 대문에 할당할 수 없었던 것을 나타낸다.
void release_pid(int pid); //pid를 반환한다.
int main()
{
    allocate_map();
    // pid_t pid, pid1;

    // /* fork a child process */
    // pid = fork();

    // if (pid < 0)
    // { /* error occurred */
    //     fprintf(stderr, "Fork Failed\n");
    //     return 1;
    // }
    // else if (pid == 0)
    // { /* child process */
    //     printf("Child Start\n");
    //     printf("Child End\n");
    //     exit(1);
    // }
    // else
    // { /* parent process */
    //     /* parent will wait for the child to complete */
    //     printf("Preant Start\n");
    //     sleep(20);

    //     printf("Preant End\n");
    // }

    return 0;
}
int allocate_map(void)
{ //pid를 나타내기 위한 자료구조를 생성하고 초기화 한다.
    //  반환값이 -1이면 실패, 값이 1이면 성공을 나타낸다.

    for (int i = 0; i < MIN_PID; i++)
    {
        pid_array[i] = -1;
    }
    for (int i = MIN_PID; i < MAX_PID; i++)
    {
        pid_array[i] = 0;
    }
    return 1; //성공

    return -1; //만약 실패라면 근데 언제 실패하지?
}
int allocate_pid(void)
{ //pid를 할당하고 반환한다.
    //반환값 -1은 모든 pid가 사용 중이기 대문에 할당할 수 없었던 것을 나타낸다.
    for (int i = MIN_PID; i < MAX_PID; i++)
    {
        if (pid_array[i] == 0)
        {
            pid_array[i]=1;
            return i;
        }
        return -1;
        
    }
}
void release_pid(int pid)
{
    //pid를 반환한다.
    pid_array[pid] = 0;
}