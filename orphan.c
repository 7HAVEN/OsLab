#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int n = fork();
  if (n == 0) {
    // child
    printf("parent pid : %d child pid %d\n", getppid(), getpid());
    sleep(2);
    printf("parent pid %d child pid %d", getppid(), getpid());
  } else {
    printf("parent pid : %d\n", getpid());
  }
  return 0;
}