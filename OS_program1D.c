/*
Author - 	Aman Maldar 
Course - 	EECE 5730 - Operating Systems
Instructor - 	Dr. M. Geiger
Project -	Program 1, Question D (+5 Points)

Problem Statement -		
 Your program is almost identical to part C , but the number of child processes is  based  on  a  command  line  argument  passed  to  your  executable.  (For  example,  if  your executable is named “proj1”, executing the command ./proj1 6
will run a version of  your  program  that  creates  6  child  processes. Assume  the  maximum  number  of  child processes is 25
*/

#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[] )
{
	printf("********Project 1 - Question D******** \n");
	pid_t pid,i;

	if (atoi(argv[1]) > 10){
		printf("Loop count should be less than 10, exiting program \n");
		exit(1);
	}
	
	for(i = 0; i < atoi(argv[1]); i++) 
	{
		pid = fork();
		
		if(pid < 0) {
			fprintf(stderr, "Fork Failed \n");
			return 1;
		} 
		else if (pid == 0){		//child process 
			//printf("Child Message  1- Entered Child Process. Do something Interesting. \n");
			printf("Child (%d): %d\n", i + 1, getpid());
			//printf("Child Message  2- Child Terminates. Fork() returns pid of child = %d to Parent \n", getpid());
			execlp("bin/ls","ls",NULL);
		}
		else{		//parent process
		//printf("Parent Message 1- Entered Parent Process, Parent waiting for child to terminate \n");
		wait(NULL);
		//printf("Parent Message 2- Child Completes and returns its pid = %d \n", getpid());
		//printf("Parent Message 3- Parent Exits \n");
	}
}
	
	return 0;
}
