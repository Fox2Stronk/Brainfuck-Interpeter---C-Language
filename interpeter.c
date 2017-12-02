#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PAGE_SIZE 4096
#define STACK_SIZE PAGE_SIZE * 8


enum Operator {INC_DP = '>',DEC_DP = '<', INC = '+', DEC = '-', OUTPUT = '.', INPUT = ',', OPEN = '[', CLOSE = ']'};

void interpretBrainFuck(char* input)
{   char array[STACK_SIZE] = {0};
    char *ptr = array;

    int i;
    size_t input_length = strlen(input);
    for( i = 0; !input[i]; i++)
        {
            int counter;

            switch(input[i])
            {

            case INC_DP:                // increase data pointer by 1
                if(*ptr<STACK_SIZE)
                    ++ptr;
                else
                    printf("ERROR! Out of stack segmant");

                break;
            case DEC_DP:
                if(*ptr>=0)                // decrease data pointer by 1
                    --ptr;
                else
                    printf("ERROR! Out of stack segmant");
                break;
            case INC:                     // increase the byte at the data pointer by 1
                ++*ptr;
                break;
            case DEC:                     // decrease the byte at the data pointer by 1
                --*ptr;
                break;
            case OUTPUT:
                if(*ptr>=0)                 // output the byte at the data pointer
                putchar(*ptr);
                else
                {
                printf("ERROR! Cannot print negative char");
                break;
                }
            case INPUT:
                *ptr = getchar();         // accept one byte of input, storing its value in the byte at the data pointer.
                break;
            case OPEN:                    // if the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching CLOSE command.
                 if (!*ptr)
                 {
                    counter = 1;
                    while (counter)
                    {
                        ++i;
                        if(i>=input_length)
                            {

                            printf("ERROR! Check for unmatching brackets.");
                            return;
                            }
                        if (input[i] == ']')
                            --counter;
                        else if (input[i] == '[')
                            ++counter;
                    }
                  }
                    break;

            case CLOSE:                    // if the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching O command.

                if (*ptr)
                {
                        counter = 1;
                        while (counter)
                    {
                        --i;
                        if(i<0)
                        {
                            printf("ERROR! Check for unmatching brackets.");
                            return;
                        }

                        if (input[i] == '[')
                            --counter;
                        else if (input[i] == ']')
                            ++counter;
                    }
                }
                        break;
             }
       }

}
