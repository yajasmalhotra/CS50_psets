#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string text = get_string("Text: ");

    float l = 0, w = 1, s = 0;       // l = letters, w = words, s = sentences

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            l++ ;                   // adds one to letter count
        } 

        if (isspace(text[i]))
        {
            w++ ;                   // adds one to word count
        }

        if ((text[i] == '.') || (text[i] == '?') || (text[i] == '!'))
        {
            s++ ;                   // adds one to senteence count
        }
    }

    float L = (l / w * 100);
    float S = (s / w * 100);
    float index = (0.0588 * L - 0.296 * S - 15.8); // raw index value
    int index_final = round(index); // final recommended reading level

    if (index_final <= 16 && index_final >= 1)
    {
        printf("Grade %i\n", index_final);
    }

    else
    {
        if (index_final < 1)
        {
            printf("Before Grade 1\n");
        }

        if (index_final > 16)
        {
            printf("Grade 16+\n");
        }
    }
}
