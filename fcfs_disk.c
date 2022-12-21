#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, intialPos;
  scanf("%d %d", &n, &intialPos);
  int posTogo, headMov = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &posTogo);
    headMov += abs(posTogo - intialPos);
    intialPos = posTogo;
  }
  printf("total head movement = %d\navg head movement = %0.3f\n", headMov,
         (float)headMov / n);
  return 0;
}