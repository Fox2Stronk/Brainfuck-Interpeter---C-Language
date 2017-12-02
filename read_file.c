#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

char * readFile(char * filename)                        // recieves a readable file and returns its content as string
    {
      FILE *f = fopen(filename, "rt");
      assert(f);                                        // check once again if there are no errors reading the file, fail the program otherwise
      fseek(f, 0, SEEK_END);
      long length = ftell(f);
      fseek(f, 0, SEEK_SET);
      char *buffer = (char * ) malloc(length + 1);
      buffer[length] = '\0';
      fread(buffer, 1, length, f);
      fclose(f);
      return buffer;
    }
