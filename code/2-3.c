#include <stdio.h>
#include <unistd.h> 

int main(void) {

  int id = fork();

  if (id != 0) {
    sleep(1); // Parent sleep
    printf("Goodbye\n");
  } else {
    printf("Hello\n");
  }

  return 0;
}