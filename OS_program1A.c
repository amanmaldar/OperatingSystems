/*
Author - 	Aman Maldar 
Course - 	EECE 5730 - Operating Systems
Instructor - 	Dr. M. Geiger
Project -	Program 1, Question A (10 Points)

Problem Statement -		
Your  program  creates  a  single  child  process,  printing at  least  one  message from  both  the  parent  and  child  
process  indicating  the  PIDs  of  those  processes. Your parent process should wait for the child to terminate and print a 
message once the child has completed.
*/

#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main()
{	
	printf("********Project 1 - Question A******** \n");
	pid_t pid;
	//fork a child process
	pid = fork();
	
	if (pid < 0) {
		fprintf(stderr, "Fork Failed \n");
		return 1;
	}
	else if (pid == 0){		//child process 
		printf("Child Message - Inside of child. Do something Interesting. \n");
		printf("Child Message - Child process terminates. Fork() returns pid of child = %d \n", pid);
		execlp("bin/ls","ls",NULL);
	}
	else{		//parent process
	printf("Parent Message - Parent waiting for child to terminate \n");
	wait(NULL);
	printf("Parent Message - Child Completes and returns it pid = %d \n", pid);
	}
	
	return 0;
}
