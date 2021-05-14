
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(void) {
  int fd;
  int pid;
  char *H24WFG = "/tmp/myfifo";
  mkfifo(H24WFG, 0666);

  pid = fork();

  if (pid == 0) {
    char msg[] = "Kanya Alexander\n";
    fd = open(H24WFG, O_WRONLY);
    write(fd, msg, strlen(msg) + 1);
    printf("Fifo letrehozva, uzenet elhelyezve.\n");
    close(fd);
    
    return 0;
  }

  char buffer[1024];
  int buffer_size = sizeof(buffer) / sizeof(char);
  fd = open(H24WFG, O_RDONLY);
  read(fd, buffer, buffer_size);
  close(fd);
  unlink(H24WFG);
  printf("Fifo megnyitva, kiolvasva, bezarva.\n");
  printf("Az uzenet a kovetkezo: %s", buffer);

  wait(NULL);

  return 0;
}