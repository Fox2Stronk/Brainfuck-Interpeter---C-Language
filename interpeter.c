#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PAGE_SIZE 4096
#define STACK_SIZE PAGE_SIZE * 8


enum Operator {INC_DP = '>', DEC_DP = '<', INC = '+', DEC = '-', OUTPUT = '.', INPUT = ',', OPEN = '[', CLOSE = ']'};

void interpretBrainFuck(char *input) // recieves a 'string' and reads & executes it as brainfuck instructions
    {
      char array[STACK_SIZE] = {0};
      char *ptr = array;
      int i;
      size_t input_length = strlen(input);
      int counter;

      for (i = 0; !input[i]; i++)
      {

        switch (input[i])
        {

            case INC_DP: // increase data pointer by 1

              if ( *ptr < STACK_SIZE) // checks if there's a stack overflow
                {
                    ++ptr;
                }
              else
                {
                    printf("ERROR! Out of stack segmant");
                }
              break;

            case DEC_DP: // decrease data pointer by 1

                if ( *ptr >= 0) // check if there's a stack underflow
                {
                    --ptr;
                }
              else
                {
                    printf("ERROR! Out of stack segmant");
                }

                break;

            case INC: // increase the byte at the data pointer by 1

                ++*ptr;
                break;

            case DEC: // decrease the byte at the data pointer by 1

                --*ptr;
                break;

            case OUTPUT: // output the byte at the data pointer

                if (*ptr >= 0) // checks that the character is not negative before it's being printed
                {
                    putchar( * ptr);
                }
                else
                {
                    printf("ERROR! Cannot print negative char");
                    return;
                }

                break;

            case INPUT:

              *ptr = getchar(); // accept one byte of input, storing its value in the byte at the data pointer.
              break;

            case OPEN: // if the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching CLOSE command.

                if (!*ptr)
                {
                    counter = 1;
                    while (counter)
                    {
                        ++i;
                        if (i >= input_length) // checks if the instruction pointer doesn't exceed limit
                        {
                            printf("ERROR! Check for unmatching brackets.");
                            return;
                        }

                        // making sure nested 'loops' work as intended; each brace should jump to its matching brace:
                        if (input[i] == ']')
                        {
                            --counter;
                        }
                        else if (input[i] == '[')
                        {
                            ++counter;
                        }

                    }
                }

                break;

            case CLOSE: // if the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching O command.

                if (*ptr)
                {
                    counter = 1;
                    while (counter)
                    {
                        --i;

                        if (i < 0)
                        {
                            printf("ERROR! Check for unmatching brackets.");
                            return;
                        }

                        // making sure nested 'loops' work as intended (each brace should jump to its matching brace:
                        if (input[i] == '[')
                        {
                            --counter;
                        }
                        else if (input[i] == ']')
                        {
                            ++counter;
                        }

                    }
                }

                break;
            }
        }

    }
