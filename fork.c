#include <stdio.h>
#include <unistd.h>

int main() {
  int n = fork();
  if (n == 0) {
    printf("child : %d\n", getpid());
    printf("parent : %d\n", getppid());
  } else {
    printf("parent parent %d\n", getpid());
  }
  return 0;
}