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
