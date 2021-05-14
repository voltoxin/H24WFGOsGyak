#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int main(int argc, char **argv) {
  pid_t pid;
  char *endptr;

  if (argc != 2) {
    printf("hasznalat: %s [pid]\n", argv[0]);
    return 0;
  }

  pid = (pid_t)strtol(argv[1], &endptr, 10);

  if (strcmp(endptr, "\0") != 0) {
    printf("a pidnek egesz szamnak kell lennie\n");
    return 0;
  }

  kill(pid, SIGALRM);
  printf("a jel elkuldve: %d\n", (int)pid);

  return 0;
}
