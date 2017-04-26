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
		printf("Loop count should be less than 25, exiting program \n");
		return 1;
	}

	printf("********Project 1 - Question F******** \n");
	pid_t pid,i,child_pid,master_pid;
	int status,j,child_number,r;
	int size = atoi(argv[1]);
	int mapping_array[size];
	char name[10];

	master_pid = getpid();
	for(i = 0; i < atoi(argv[1]); i++) 
	{
		if(master_pid == getpid())
		{		
			pid = fork();
			mapping_array[i+1] = pid;
			//j++;
		}

		if(pid < 0) {
			fprintf(stderr, "Fork Failed \n");
			return 1;
		} 
		else if (pid == 0){		//child process 

			printf("Child (%d) : created %d \n", i + 1, getpid());
			//mapping_array[i+1] = getpid();
			//printf("Mapping array is (%d)  \n",mapping_array[i+1]);
			sleep(1);
			r = (i+1) % 5;
			if (r == 0) {r =5;}
			sprintf(name, "./test%d",r);
			execlp(name,"ls",NULL);
			exit(0);
		}
		
	}
	for(i = 0; i < atoi(argv[1]); i++) 
	{

		child_pid = wait(&status);

		for (j =1 ; j <= atoi(argv[1]); j++)
		{
			if (mapping_array[j] == child_pid)
			{
				child_number = 	j;				
				break;					
			}
		}
		printf("Parent know child_id (%d) | child_number (%d) is finished     \n",child_pid,child_number);
		//printf("Mapping array is (%d)  \n",mapping_array[i+1]);
	
	}
	
	return 0;
}
