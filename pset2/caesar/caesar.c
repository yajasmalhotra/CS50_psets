#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    for  (int q = 0, u = strlen(argv[1]); q < u; q++)
    {
        if (isalpha(argv[1][q]))
        {
            printf("Usage: ./caesar key");
            return 1;
        }
    }
    
    if (argc != 2 || atoi(argv[1]) < 0)
    {
        printf("Usage: ./caesar key");    
        return 1;
    }
    
    else
    {    
        int key = atoi(argv[1]);                // converts key to integer
        
        string p = get_string("Plaintext: ");   // gets user input
        printf("ciphertext: ");
        
        if (p != NULL)
        {
            for (int i = 0, n = strlen(p); i < n; i++)
            {
                if (isupper(p[i]))              // for uppercase letters
                {
                    printf("%c", (p[i] + key - 65) % 26 + 65);
                }
                else if (islower(p[i]))         // for lowercase letters
                {
                    printf("%c", (p[i] + key - 97) % 26 + 97);   
                }
                else                            // for other characters
                {
                    printf("%c", p[i]);
                }
            }
        }
        
        printf("\n");
        return 0; 
    }
}   

