#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {

  srand(time(NULL));
  
  int status, kid2;
  int kid1 = fork();
  
  if(kid1) {
    printf("%d is the Parent\n", getpid());
    kid2 = fork();
    if (kid2) {
      int fast = wait(&status);
      printf("%d: %d Slept for %d seconds\n", getpid(), fast, WEXITSTATUS(status));
      return 0;
    }
    else {
      printf("Child pid: %d\n", getpid());
      int sleeps = rand() % 15 + 5;
      sleep(sleeps);
      printf("%d is finished sleeping for %d seconds\n", getpid(), sleeps);
      return sleeps;
    }  
  }
  
  else {
    printf("Child pid: %d\n", getpid());
    int sleeper = rand() % 15 + 5;
    sleep(sleeper);
    printf("%d is finished sleeping for %d seconds\n", getpid(), sleeper);
    return sleeper;
  }
  
  return 0;
}
