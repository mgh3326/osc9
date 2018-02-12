#include <stdio.h>

void main(){
    int num=443;
    int i=1;
    while(1)
    {
        num=num/10;
        printf("i: %d  num : %d\n",i,num);
        if(num==0)
        break;
        i++;
    }
}