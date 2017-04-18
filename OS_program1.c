//the program for assignement 1 goes here

#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main
{
	pid_t pid;
	//fork a child process
	pid = fork();
	
	if (pid < 0) {
		fprintf(stderr, "Fork Failed \n");
		return 1;
	}
	else if (pid == 0){//child process 
		printf("Inside of child. Do something \n")
		printf("Child process terminates \n");
		execlp("bin/ls","ls",NULL);
	}
	else{//parent process
	wait(NULL);
	printf("Child Completes and returns it pid to parent \n");
	}
	retun 0;
}
