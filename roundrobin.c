#include "queue.h"
typedef struct process_structure {
  int pid;
  int arrivalTime;
  int burstTime;
  int burstTimeLeft;
  int responseTime;
  int turnAroundTime;
  int completionTime;
  int waitTime;
  int startTime;
} process;

// int isExecuting(int n, int *runningProcess) {
//   int finisedFlag = 0;
//   for (int i = 0; i < n; i++) {
//     if (runningProcess[i] == 1) {
//       finisedFlag = 1;
//       break;
//     }
//   }
//   return finisedFlag;
// }
int isExecuting(int n, process *p) {
  int finisedFlag = 0;
  for (int i = 0; i < n; i++) {
    if (p[i].burstTimeLeft == 0) {
      finisedFlag = 1;
      break;
    }
  }
  return finisedFlag;
}

void print(int n, process *p) {
  printf("pid\tat\tbt\tct\ttat\twt\trt\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrivalTime,
           p[i].burstTime, p[i].completionTime, p[i].turnAroundTime,
           p[i].waitTime, p[i].responseTime);
  }
}

void sortByArrivaTime(int n, process *p) {

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (p[i].arrivalTime > p[j].arrivalTime) {
        process temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
    }
  }
}
int processArrived(int time, process *p, int size) {
  // this will fail if 2 process arrive at the same time
  for (int i = 0; i < size; i++) {
    if (p[i].arrivalTime == time)
      return p[i].pid;
  }
  return -1;
}
int main() {

  int n;
  printf("enter the number of processes:");
  scanf("%d", &n);
  int runningProcess[n]; // this array contains boolean values 1 /0  to denote
                         // running status of a process
  int processOrder[n];
  process p[n];
  for (int i = 0; i < n; i++) {
    int arrivalTime, burstTime;
    scanf("%d %d", &arrivalTime, &burstTime);
    p[i].pid = i;
    p[i].arrivalTime = arrivalTime;
    p[i].burstTime = burstTime;
    p[i].burstTimeLeft = burstTime;
    p[i].startTime = -1;
    p[i].completionTime = -1;
    p[i].turnAroundTime = -1;
    p[i].waitTime = -1;

    runningProcess[i] = 1;
  }
  int timeQuanta;
  printf("Enter the time quanta: ");
  scanf("%d", &timeQuanta);
  // sortByArrivaTime(n, p);
  int ProcessQueue[n];
  int front = -1, rear = -1;
  // fill
  int isRunning = 1; // set flag true
  int time = 0;
  while (isExecuting(n, p)) {

    int newProcessPid = processArrived(time, p, n);
    if (newProcessPid != -1) {
      enqueue(newProcessPid, &front, &rear, ProcessQueue, n);
    }
    if (!isEmpty(front, rear)) {
      int runningProcessPid = dequeue(&front, &rear, ProcessQueue, n);
      int burst = p[runningProcessPid].burstTimeLeft;
      if (p[runningProcessPid].startTime == -1)
        p[runningProcessPid].startTime = time;
      if (burst <= timeQuanta) {
        time += burst;
        p[runningProcessPid].burstTimeLeft = 0;
        p[runningProcessPid].completionTime = time;
      } else {
        time += timeQuanta;
        p[runningProcessPid].burstTimeLeft -= timeQuanta;
        enqueue(runningProcessPid, &front, &rear, ProcessQueue, n);
      }
    } else {
      time += 1;
    }
  }
  printf("time : %d\n", time);
  print(n, p);

  return 0;
}