#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    int pid;
    
    if((pid = fork()) < 0)
    	perror("fork error");
    
    else if (pid == 0)    
        {
        if(execlp("pwd", "child", (char *)NULL) < 0)
        	perror("execl error");
        }
    
    else
    	{
    	wait(0);
        printf("A gyerek sikeresen lefutott.\n");
        }
        
    return 0;
}
