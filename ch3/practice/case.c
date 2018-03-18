#include<stdio.h>

char UptoLowerOrLowertoUpCase(char c){
    if (c >= 'A' && c <= 'Z') {
         c = c + 32;
      }
      else if (c >= 'a' && c <= 'z') {
         c = c - 32;
      }
      return c;
}

int main(void){
char input ='a';
printf("(%c)\n",input);
input = UptoLowerOrLowertoUpCase(input);
printf("(%c)\n",input);
}