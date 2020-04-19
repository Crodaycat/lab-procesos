#include <stdio.h> // Input/Output printf()
#include <stdlib.h> // exit()
#include <unistd.h> // Procesos fork()
#include <fcntl.h> // Archivos open()
#include <string.h> // strlen

int main(void) {
  int fileDescriptor = open("../files/texto.txt", O_RDWR);

  if (fileDescriptor < 0) { perror("Error abriendo archivo"); exit(1); }

  int pid = fork();

  /*char *buffer = (char *) calloc(100, sizeof(char));

  int readedBytesCount = read(fileDescriptor, buffer, 10);

  buffer[readedBytesCount] = '\0';*/

  if (pid != 0) {
    // printf("Proceso padre bytes leidos: %s\n", buffer);
    write(fileDescriptor, "Hola desde el proceso padre\n", strlen("Hola desde el proceso padre\n"));
  } else {
    // printf("Proceso hijo bytes leidos: %s\n", buffer);
    write(fileDescriptor, "Hola desde el proceso hijo\n", strlen("Hola desde el proceso hijo\n"));
  }

  close(fileDescriptor);

  return 0;
}