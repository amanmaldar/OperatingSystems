/*
Authors - 	
1) Aman Maldar (01670909)
2) Vishnu Vardhan Reddy Donthi (01646354)
Authors have worked in colaboration on different parts of the project to come up with final solution.

Course - 	EECE 5730 - Operating Systems
Instructor - 	Dr. M. Geiger
Project -	Program 1

References for code -
1) POSIX Library - http://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html
2) Silberschatz, Galvin, and Gagne's Operating System Concepts
3) OpenStack discussion forums (multiple answers)
4) Printf statements are used from sample output provided by Dr. Geiger.
   http://mjgeiger.github.io/OS/projects/OS_proj1.pdf
5) Code involves some key developments derived after Discussions with Peter (TA), RakeshKiran Musaley (OS Class collegue).
6) Sample Executables - Provided by Dr. Geiger
   http://mjgeiger.github.io/OS/projects/OS_proj1.pdf
7) Modulus operator - http://www.cprogramming.com/tutorial/modulus.html

Apart from abaove references, no code has been reused. 
*/

#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>


int main(int argc, char *argv[] )
{
	//following piece of code ensures, number of child processes entered are not greater than 25
	if (atoi(argv[1]) > 25){
		printf("Child count should be less than 25, exiting program \n");
		return 1;
	}

	printf("********Project 1 - Operating Systems******** \n");
	pid_t pid,i,child_pid,master_pid;
	int status,j,child_number,r;
	int size = atoi(argv[1]);	//array size is based on number of children requested by user
	int mapping_array[size];	//stores the mapping of child number(as an index value) and child pid
	char name[10];			//used to store name of executables

	master_pid = getpid();		//master_pid is stored in the beginning to associate forking capabilities with parent only in subsequest fork() in loop 
	printf("Parent PID is %d \n",master_pid);
	//create multiple child using for loop
	for(i = 0; i < atoi(argv[1]); i++) 
	{
		//only parent is allowed to fork(). If condition ensures, fork() occurs only if parent is executing.
		if(master_pid == getpid())
		{		
			pid = fork();
			mapping_array[i+1] = pid;	//store ID of a child in the mapping_array at corresponding 'child_number' location
		}

		if(pid < 0) {
			fprintf(stderr, "Fork Failed \n");
			return 1;
		} 
		else if (pid == 0){		//child process 

			printf("Started Child (%d) with PID %d \n", i + 1, getpid());
			//put the child process to sleep to ensure all the children are created before first child completes.
			sleep(1);
			//decide which program to execute by child. I have used mod(5) function.
			//child 1 runs test1, child 2 runs test2 and so on..
			r = (i+1) % 5;
			if (r == 0) {r =5;}
			sprintf(name, "./test%d",r);
			execlp(name,"ls",NULL);		//runs the executable
			exit(0);			//child exits after it is completed
		}		
	}
	
	// following piece of code is executed by parent only.
	// Code checks for the exist status of all the childs using wait() call multiple times.
	if (pid > 0)
	{
		for(i = 0; i < atoi(argv[1]); i++) 
		{

			child_pid = wait(&status);
			//using for() loop, child PIDs are compared against PIDs stored in mapping_array; to find out child number
			//note - child numbers are same as array index. 
			for (j =1 ; j <= atoi(argv[1]); j++)
			{
				if (mapping_array[j] == child_pid)
				{
					child_number = 	j;				
					break;					
				}
			}
			printf("Parent Message - Child (%d) | (PID %d) finished \n",child_number,child_pid);
		}
	}
	return 0;
}
