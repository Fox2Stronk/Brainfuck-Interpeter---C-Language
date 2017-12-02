#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include "interpeter.h"
#include "read_file.h"




int main(int argc, char * * argv) {
  if (argc == 2) {
    if (access(argv[1], F_OK) != -1) {
      char * content = readFile(argv[1]);
      interpretBrainFuck(content);
      return 0;
    } else {
      printf("ERROR! Can't open file / file doesn't exist.");
      return 0;

    }
  }
  printf("ERROR! please enter a single argument; the file's path.");
  return 0;
}
