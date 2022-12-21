#include <stdio.h>
#include <unistd.h>

int main() {
  int p[2];
  char msg[25] = "hello world";
  int n = pipe(p);
  if (n == -1) {
    printf("pipe creation failed\n");
    return -1;
  }
  char readMsg[25];
  write(p[1], msg, sizeof(msg));
  printf("message written to pipe\n");
  read(p[0], readMsg, sizeof(readMsg));
  printf("msg read from pipe : %s\n", readMsg);

  return 0;
}