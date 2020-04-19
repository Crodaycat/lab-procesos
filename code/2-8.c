#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int pipeDesc[2];
  pipe(pipeDesc);

  if (fork() == 0) {

    dup2(pipeDesc[1], STDOUT_FILENO);
    printf("Hola mundo desde el hijo 1\n");

  } else {
    if (fork() == 0) {
      dup2(pipeDesc[0], STDIN_FILENO);

      char buffer[101];
      fgets(buffer, 100, stdin);

      printf("Hijo 2 recibe: %s\n", buffer);
    }
  }

  return 0;
}