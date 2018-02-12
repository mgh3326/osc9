#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
int main()
{
    char s1[10];    // 변환한 문자열을 저장할 배열
    int num1 = 283; // 283은 정수
    const int SIZE = 4096;
    const char *name = "OS";
    const char *message0 = "Studying ";
    const char *message1 = "Operating Systems ";
    const char *message2 = "Is Fun!";

    int shm_fd;
    void *ptr;
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

    /* configure the size of the shared memory segment */
    ftruncate(shm_fd, SIZE);

    /* now map the shared memory segment in the address space of the process */
    ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    sprintf(s1, "%d", num1); // %d를 지정하여 정수를 문자열로 저장

    printf("%s\n", s1); // 283
    sprintf(ptr, "%d", num1);
    ptr += 3;
    sprintf(ptr, "%s", s1);
    ptr += strlen(s1);
    num1 = 444;
    sprintf(s1, "%d", num1); // %d를 지정하여 정수를 문자열로 저장

    printf("%s\n", s1); // 283
    sprintf(ptr, "%d", num1);
    ptr += 3;
    sprintf(ptr, "%s", message0);
    ptr += strlen(message0);
    sprintf(ptr, "%s", message1);
    ptr += strlen(message1);
    sprintf(ptr, "%s", message2);
    ptr += strlen(message2);
    num1=4;
    sprintf(s1, "%d", num1); // %d를 지정하여 정수를 문자열로 저장
    printf("test: %s\n\n",s1);
    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED)
    {
        printf("Map failed\n");
        exit(-1);
    }
    printf("%s", ptr);
    return 0;
}