#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include "interpeter.h"
#include "read_file.h"




int main(int argc, char * * argv) {

  if (argc == 2)  // check number of arguments
    {
        if (access(argv[1], F_OK) != -1) // check if file exists & is readable
        {
          char *content = readFile(argv[1]);
          interpretBrainFuck(content);
        }
        else
        {
          printf("ERROR! Can't open file / file doesn't exist.");
        }
    }
  else
    {
        printf("ERROR! please enter a single argument; the file's path.");
    }
  return 0;
}
