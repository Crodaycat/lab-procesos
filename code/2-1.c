#include <stdio.h>
#include <unistd.h> 

int main(void) {
  int x = 100;

  int id = fork();

  if (id == 0) {
    x += 50;
    printf("Valor en el proceso padre de X: %d\n", x);
  } else {
    printf("Valor en el proceso hijo de X: %d\n", x);
  }

  return 0;
}