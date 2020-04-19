#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h>

int main(void) {

  int pid = fork();

  if (pid != 0) {
    int wRes = waitpid(pid,0, 0);
    printf("Goodbye, wait: %d\n", wRes);
  } else {
    printf("Hello\n");
    close(STDOUT_FILENO);
    printf("STDOUT closed\n");
  }

  return 0;
}