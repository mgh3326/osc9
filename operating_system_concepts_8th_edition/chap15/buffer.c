/**
 * buffer.c
 * 
 * A simple program that may be vulnerable to a buffer overflow condition.
 *
 * Figure 15.2
 */

#include <stdio.h>
#include <string.h>

// the text lists size as 256. We use a smaller size 
// to generate the overflow more easily.
#define BUFFER_SIZE 10 

int main(int argc, char *argv[])
{
	char buffer[BUFFER_SIZE];

	if (argc < 2)
		return -1;
	else {
		strcpy(buffer,argv[1]);
		
		return 0;
	}
}
