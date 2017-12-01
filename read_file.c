#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

char *readFile(char *filename) {
    FILE *f = fopen(filename, "rt");

    assert(f);
    fseek(f, 0, SEEK_END);
    long length = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *buffer = (char *) malloc(length + 1);
    buffer[length] = '\0';
    fread(buffer, 1, length, f);
    fclose(f);
    return buffer;
}
