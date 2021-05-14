#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

volatile sig_atomic_t done = 0;

void term(int signum)
{
   printf("SIGTERM Caught!\n");
   done = 1;
}

int main(int argc, char *argv[])
{
    struct sigaction action;
    memset(&action, 0, sizeof(action));
    action.sa_handler = term;
    sigaction(SIGTERM, &action, NULL);

    int pid = getpid();
    printf("PID is %d \n",pid);

    int fd1;
  
    // FIFO file path
    char * myfifo = "/tmp/myfifo";
  
    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    mkfifo(myfifo, 0777);
  
    char str1[80];
    int i = 1;

    FILE *f = fopen("file.txt", "w");
    if (f == NULL)
    {
    	printf("Error opening file!\n");
    }


    while (!done)
    {
        // First open in read only and read
        int fd1 = open(myfifo,O_RDONLY);
        read(fd1, str1, sizeof(str1));
  	
        // Print the read string and close
        if (fd1 != -1) {
		printf("A kiolvasott szo: %s\n",str1);
		fprintf(f, "Sorszam: %d  Szo: %s\n",i,str1);
	}
        close(fd1);
	i++;
    }
    fclose(f);
    printf("Done.\n");
    return 0;
}
