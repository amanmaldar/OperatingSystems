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
	pid_t pid_1,pid_2,pid_3;
	//fork a child process
	pid_1 = fork();
	pid_2 = fork();
	pid_3 = fork();
	
	if (pid < 0) {
		fprintf(stderr, "Fork Failed \n");
		return 1;
	}
	else if (pid == 0){		//child process 
		printf("Child Message  - Entered Child Process. Do something Interesting. \n");
		printf("Child Message  - Child Terminates. Fork() returns pid of child = %d to Parent \n", pid);
		execlp("bin/ls","ls",NULL);
	}
	else{		//parent process
	printf("Parent Message - Entered Parent Process, Parent waiting for child to terminate \n");
	wait(NULL);
	printf("Parent Message - Child Completes and returns its pid = %d \n", getpid());
	printf("Parent Message - Parent Exits \n");
	}
	
	return 0;
}
