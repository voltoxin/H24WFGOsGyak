#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

#define SECONDS 1

void pass(int signal_num) {}
void handle_interrupt(int signal_num);

int main(void) {
  signal(SIGINT, handle_interrupt);
  signal(SIGALRM, pass);

  for (int i = 0; i < 5; i++) {
    printf("varakozok %d masodpercig\n", SECONDS);
    alarm(SECONDS);
    pause();
    printf("itt vagyok\n");
  }

  return 0;
}

void handle_interrupt(int signal_num) {
  char msg[] = "a jelet megkaptam\n";
  write(STDOUT_FILENO, msg, strlen(msg));
  signal(SIGINT, SIG_IGN);
}
