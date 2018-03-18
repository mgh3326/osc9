/**
 * Example program demonstrating UNIX pipes.
 *
 * Figures 3.25 & 3.26
 *
 * @author Silberschatz, Galvin, and Gagne
 * Operating System Concepts  - Ninth Edition
 * Copyright John Wiley & Sons - 2013
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 25
#define READ_END	0
#define WRITE_END	1
char UptoLowerOrLowertoUpCase(char c){
    if (c >= 'A' && c <= 'Z') {
         c = c + 32;
      }
      else if (c >= 'a' && c <= 'z') {
         c = c - 32;
      }
      return c;
}
int main(int argc, char* argv[])
{
	char write_msg[BUFFER_SIZE];
	printf("Input please : ");
	fgets(write_msg, BUFFER_SIZE, stdin); // white space in input OK
	char read_msg[BUFFER_SIZE];
	pid_t pid;
	int fd[2];

	/* create the pipe */
	if (pipe(fd) == -1) {
		fprintf(stderr,"Pipe failed");
		return 1;
	}

	/* now fork a child process */
	pid = fork();

	if (pid < 0) {
		fprintf(stderr, "Fork failed");
		return 1;
	}

	if (pid > 0) {  /* parent process */
		/* close the unused end of the pipe */
		close(fd[READ_END]);

		/* write to the pipe */
		write(fd[WRITE_END], write_msg, strlen(write_msg)+1); 

		/* close the write end of the pipe */
		close(fd[WRITE_END]);
	}
	else { /* child process */
		/* close the unused end of the pipe */
		close(fd[WRITE_END]);

		/* read from the pipe */
		read(fd[READ_END], read_msg, BUFFER_SIZE);
		char output_msg[BUFFER_SIZE];
		for(int i=0;i<strlen(read_msg)-1;i++)
		{
			// printf("(%c)\n",read_msg[strlen(read_msg)-2-i]);
			read_msg[i] = UptoLowerOrLowertoUpCase(read_msg[i]);

		}
		printf("%s\n",read_msg);

		/* close the write end of the pipe */
		close(fd[READ_END]);
	}

	return 0;
}
