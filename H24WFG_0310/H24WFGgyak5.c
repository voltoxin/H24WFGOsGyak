#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define n 3

int main(void)
{
	pid_t pid[n];
	int status[n];
	
	for (int i = 0; i < n; i++)
		{
		pid[i] = fork();
		
		if (pid[i] < 0) 
			{
			perror("fork error");
			return -1;
			}
			
		else if (pid[i] == 0)
			{
			if (i == 0)
				{
				printf("1. gyerek: exit\n");
				exit(0);
				}
			else if (i == 1)
				{
				printf("2. gyerek: abort\n");
				abort();
				}
			else
				{
				printf("3. gyerek: nullaval osztas\n");
				printf("%d", 10/0);
				}
			
			return 0;
			}
		sleep(1);
		}
		for (int i = 0; i < n; i++)
			{
			wait(&status[i]);
			}		
		printf("Minden child processz lefutott.\n");
		printf("Exit child PID: %d Exit statusz: %d\n", pid[0], status[0]);
		printf("Abort child PID: %d Exit statusz: %d\n", pid[1], status[1]);
		printf("Nullaval osztas child PID: %d Exit statusz: %d\n", pid[2], status[2]);
	
	return 0;
}
