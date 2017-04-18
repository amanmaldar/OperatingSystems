/*
Author - 	Aman Maldar 
Course - 	EECE 5730 - Operating Systems
Instructor - 	Dr. M. Geiger

Project -	Program 1, Question B (+5 Points)

Problem Statement -		
Your program creates multiple child processes without using a loop, printing messages at the start and end of each process as 
described in part A. 
*/

#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("********Project 1 - Question B******** \n");
	pid_t pid;
	//fork a child process
	pid = fork();
	
	if (pid < 0) {
		fprintf(stderr, "Fork Failed \n");
		return 1;
	}
	else if (pid == 0){//child process 
		printf("Inside of child. Do something \n");
		printf("Child process terminates \n");
		execlp("bin/ls","ls",NULL);
	}
	else{//parent process
	wait(NULL);
	printf("Child Completes and returns it pid to parent \n");
	}
	return 0;
}
