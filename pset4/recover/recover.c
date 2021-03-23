#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <cs50.h>

#define blocksize 512
#define namesize 8

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)          
    {
        printf("Usage: ./recover image \n");
        return 1;
    }
    
    char *infile = argv[1];
    if (infile == NULL)
    {
        printf("Usage: ./recover image \n");
        return 1;
    }
    
    FILE *inPtr = fopen(infile, "r");
    if (inPtr == NULL)
    {
        printf("Could not open %s \n", infile);
        return 1;
    }
  
    BYTE buffer[blocksize];
    char filename[namesize];
    FILE *outPtr = NULL;
    int counter = 0;
    
    while (fread(buffer, sizeof(BYTE), blocksize, inPtr) || feof(inPtr) == 0)
    {
        if
        (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        
        { 
            if (outPtr != NULL)
            {
                fclose(outPtr);
            }
            sprintf(filename, "%03d.jpg", counter);
            outPtr = fopen(filename, "w");
            counter += 1;
        }
        if (outPtr != NULL)
        {
            fwrite(buffer, blocksize, 1, outPtr);
        }
    }
    if (outPtr == NULL)
    {
        fclose(outPtr);
    }
}
