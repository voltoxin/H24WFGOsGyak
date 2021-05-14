#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
  
int main()
{
    int fd;
  
    // FIFO file path
    char * myfifo = "/tmp/myfifo";
  
    // Creating the named file(FIFO)
    // mkfifo(<pathname>, <permission>)
    mkfifo(myfifo, 0777);
  
    char str[80];
    while (1)
    {
        // Open FIFO for write only
        fd = open(myfifo, O_WRONLY);
  	fflush(stdin);
	printf("Adj meg egy szot: ");
        // Take an input arr1ing from user.
        // 80 is maximum length
        scanf ("%79s",str);
        // Write the input arr1ing on FIFO
        // and close it
        write(fd, str, strlen(str)+1);
        close(fd);
	fflush(stdin);
      }
    return 0;
}
