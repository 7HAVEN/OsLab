#include <stdio.h>

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
void sortbyArrivalTime(int size, process *p) {
  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
      if (p[i].arrivalTime > p[j].arrivalTime) {
        process temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  process p[n];
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &p[i].arrivalTime, &p[i].burstTime);
    p[i].pid = i;
  }
  sortbyArrivalTime(n, p);
  int time = 0;
  const int contextSwitch = 0;
  for (int i = 0; i < n; i++) {
    time += contextSwitch; // context switch
    p[i].startTime = time;
    time += p[i].burstTime;
    p[i].completionTime = time;
    p[i].responseTime = p[i].startTime - p[i].arrivalTime;
    p[i].turnAroundTime = p[i].completionTime - p[i].arrivalTime;
    p[i].waitTime = p[i].turnAroundTime - p[i].burstTime;
  }
  float avgWaitTime, avgTurnAroundTime, avgResponseTime;
  float sumWaitTime = 0.0f, sumTurnaroundTime = 0.0f, sumResponseTime = 0.0f;
  printf("pid\tat\tbt\tct\trt\ttat\twt\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrivalTime,
           p[i].burstTime, p[i].completionTime, p[i].responseTime,
           p[i].turnAroundTime, p[i].waitTime);
    sumWaitTime += p[i].waitTime;
    sumTurnaroundTime += p[i].turnAroundTime;
    sumResponseTime += p[i].responseTime;
  }
  avgWaitTime = sumWaitTime / n;
  avgTurnAroundTime = sumTurnaroundTime / n;
  avgResponseTime = sumResponseTime / n;
  float througput = (float)time / n;
  printf("avg wait time = %0.3f\navg response time = %0.3f\navg turn around "
         "time = %0.3f\nthrough put =%0.3f\n",
         avgWaitTime, avgResponseTime, avgTurnAroundTime, througput);
  return 0;
}