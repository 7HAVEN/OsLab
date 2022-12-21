#include <stdio.h>
#include <stdlib.h>
void sort(int size, int *arr) {
  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
      if (arr[i] > arr[j]) {
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  }
}
int findIndex(int n, int size, int *arr) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == n)
      return i;
  }
  return -1;
}

int main() {
  int n, initialPos;
  scanf("%d %d", &n, &initialPos);
  int readLoc[n + 1];
  readLoc[n] = initialPos;
  for (int i = 0; i < n; i++) {
    scanf("%d", &readLoc[i]);
  }
  sort(n + 1, readLoc);
  int start = findIndex(initialPos, n + 1, readLoc);
  int headmov = 0;
  // we go to left
  printf("start = %d\n sorted array :", start);
  for (int i = 0; i <= n; i++) {
    printf("%d ", readLoc[i]);
  }
  printf("\n");
  for (int i = start; i >= 0; i--) {
    printf("%d %d\n", initialPos, readLoc[i]);
    headmov += abs(initialPos - readLoc[i]);
    initialPos = readLoc[i];
  }
  headmov += readLoc[0];
  initialPos = 0;
  for (int i = start; i <= n; i++) {
    headmov += abs(initialPos - readLoc[i]);
    initialPos = readLoc[i];
  }
  printf("head mov = %d\n", headmov);

  return 0;
}