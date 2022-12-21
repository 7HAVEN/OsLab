#include <stdio.h>
int isEmpty(int front, int rear) { return (front == -1 ? 1 : 0); }
int isFull(int front, int rear, int size) {
  if (rear + 1 == front || (rear == size - 1 && front == 0))
    return 1;
  return 0;
}

void enqueue(int pid, int *front, int *rear, int *items, int size) {
  if (*front == -1)
    *front = *front + 1;
  *rear += (*rear + 1) % size;
  items[*rear] = pid;
}

int dequeue(int *front, int *rear, int *items, int size) {
  if (isEmpty(*front, *rear))
    return -1;
  int n = items[*front];
  if (*front == *rear) {
    *front = -1;
    *rear = -1;
  } else {
    *front = (*front + 1) % size;
  }
  return n;
}
