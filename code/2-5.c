#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h>

int main(void) {

  int pid = fork();

  if (pid != 0) {
    int wRes = wait(&pid);
    printf("Goodbye, wait: %d\n", wRes);
  } else {
    int wRes = wait(0);
    printf("Hello, wait: %d\n", wRes);
  }

  return 0;
}