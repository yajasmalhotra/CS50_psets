#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i, j;
    int n;
    do
    {
        n = get_int("Height: ");
    }
        while (n < 1 || n > 8);
    for
    (i = 0; i < n; i++)
    {
        for
        (j = 0; j < n-1-i; ++j)
        printf(" ");                    // left pyramid
        for
        (j = 0; j < 1 + i; ++j)
        printf("#");

        printf("  ");                   // spaces between pyramids
        for
        (j = 0; j < 1 + i; ++j)
        printf("#");
        for
        (j = 0; j < n-1-i; ++j)        // right pyramid
        printf("");

        printf("\n");
    }
}