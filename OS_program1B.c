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

main()
{
	printf("********Project 1 - Question B******** \n");
	pid_t pid;
	//fork a child process
	printf("fork() call - 1 \n");
	pid = fork(); 
	printf("fork() call - 2 \n");
	pid = fork();
	printf("fork() call - 3 \n");
	pid = fork(); 
	
	if (pid < 0) {
		fprintf(stderr, "Fork Failed \n");
		return 1;
	}
	else if (pid == 0){		//child process 
		printf("Child Message  1- Entered Child Process. Do something Interesting. \n");
		printf("Child Message  2- Child Terminates. Fork() returns pid of child = %d to Parent \n", getpid());
		execlp("bin/ls","ls",NULL);
	}
	else{		//parent process
		printf("Parent Message 1- Entered Parent Process, Parent waiting for child to terminate \n");
		wait(NULL);
		printf("Parent Message 2- Child Completes and returns its pid = %d \n", getpid());
		printf("Parent Message 3- Parent Exits \n");
	}
	
	exit(0);
	//return 0;
}
