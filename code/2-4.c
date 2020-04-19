#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h> 



int main(void) {

  int id = fork();

  if (id != 0) {
    char *args[] = {"/bin/ls", NULL};
    char *env[] = { NULL };

    //execl(args[0], args[0], NULL);
    //execle(args[0], args[0], NULL, env);
    //execv(args[0], args);
    //execvp(args[0], args);
    execvpe(args[0], args, env);
  }

  return 0;
}