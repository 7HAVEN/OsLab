#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
  int n = fork();
  if (n == 0) {
    printf("child finished execution\n");
    exit(0);
  } else {
    sleep(3);
    printf("parent finised execution\n");
  }
  return 0;
}