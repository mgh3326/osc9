

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
int length_int(int num);
int main()
{

    pid_t pid, pid1;
    int num = 0;
    char temp_array[10]; // 변환한 문자열을 저장할 배열
    int temp_num = 0;    // initialize
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
        const int SIZE = 4096;
        const char *name = "OS";
        const char *message0 = "Studying ";
        // const char *message1 = "Operating Systems ";
        // const char *message2 = "Is Fun!";

        int shm_fd;
        void *ptr;
        // char oh[100];

        /* create the shared memory segment */
        shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

        /* configure the size of the shared memory segment */
        ftruncate(shm_fd, SIZE);

        /* now map the shared memory segment in the address space of the process */
        ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
        if (ptr == MAP_FAILED)
        {
            printf("Map failed\n");
            return -1;
        }

        /**
	 * Now write to the shared memory region.
 	 *
	 * Note we must increment the value of ptr after each write.
	 */
        // sprintf(ptr, "%s", message0);
        // ptr += strlen(message0);
        // sprintf(ptr, "%s", message1);
        // ptr += strlen(message1);
        // sprintf(ptr, "%s", message2);
        // ptr += strlen(message2);

        while (num > 0)
        {
            sprintf(ptr, "%d", num); // %d를 지정하여 정수를 문자열로 저장
            ptr += length_int(num);
            if (num == 1)
            {
                //printf("%d\n", num);
                // sprintf(temp_array, "%d", num); // %d를 지정하여 정수를 문자열로 저장
                // sprintf(ptr, "%s", temp_array);
                // ptr += strlen(temp_array);
                
                sprintf(ptr, "\n");
                ptr += strlen("\n");
                break;
            }
            // printf("%d, ", num);
            // sprintf(temp_array, "%d", num); // %d를 지정하여 정수를 문자열로 저장
            // sprintf(ptr, "%s", temp_array);
            // ptr += strlen(temp_array);
            // sprintf(ptr, "%d", num); // %d를 지정하여 정수를 문자열로 저장
            // ptr += length_int(num);
            sprintf(ptr, ", ");
            ptr += strlen(", ");
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
        wait(NULL); //동기화를 위함
        const char *name = "OS";
        const int SIZE = 4096;

        int shm_fd;
        void *ptr;
        int i;

        /* open the shared memory segment */
        shm_fd = shm_open(name, O_RDONLY, 0666);
        if (shm_fd == -1)
        {
            printf("shared memory failed\n");
            exit(-1);
        }

        /* now map the shared memory segment in the address space of the process */
        ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
        if (ptr == MAP_FAILED)
        {
            printf("Map failed\n");
            exit(-1);
        }

        /* now read from the shared memory region */
        printf("%s", ptr);

        /* remove the shared memory segment */
        if (shm_unlink(name) == -1)
        {
            printf("Error removing %s\n", name);
            exit(-1);
        }
    }

    return 0;
}
int length_int(int num)
{
    int index = 1;
    while (1)
    {
        num = num / 10;

        if (num == 0)
            break;
        index++;
    }
    return index;
}