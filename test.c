#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        system("gcc");
    }
    else
    {
        int index = 0;
        while (argv[1][index])
        {
            index++;
        }
        //char str2[index-2] = {0};
        //char *arr = (char *)malloc(sizeof(char) *3+1+ index - 2+1+index);
        char *arr = (char *)malloc(sizeof(char) * (3 + 2 * index));
        int oh_i = 0;
        arr[0] = 'g';
        arr[1] = 'c';
        arr[2] = 'c';
        arr[3] = ' ';
        arr[4] = '-';
        arr[5] = 'o';
        arr[6] = ' ';
        //arr="gcc ";
        for (int i = 0; i < index - 2; i++)
        {
            arr[i + 7] = argv[1][i];
        }
        arr[5 + index] = ' ';
        for (int i = 0; i < index; i++)
        {
            arr[6 + index + i] = argv[1][i];
        }
        //printf("ohoh(%s)(%s)\n", arr, argv[1]);
        system(arr);
        free(arr);
    }

    return 0;
}