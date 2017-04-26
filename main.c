#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>

//__thread int mapping_array[10]; 
//static __thread int mapping_array[10]; 

int main(int argc, char *argv[] )
{
	printf("********Project 1 - Question C******** \n");
	pid_t pid,i,child_pid,master_pid;
	int status,j,child_number;
	int mapping_array[10];

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
			execlp("./test1","ls",NULL);
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
