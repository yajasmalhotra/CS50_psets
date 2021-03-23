#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int n = 0;              // number of coins owed
    
    float c;                // amount of change owed
    do
    {
        c = get_float("Change Owed: ");
    }
    while (c < 0);
    
    c = c * 100;            // prevents
    c = round(c);           // float imprecision
    
    while (c >= 25)
    {
        (c = c - 25);
        n ++;
    }
    while (c < 25 && c >= 10)
    {
        (c = c - 10);
        n ++;
    }
    while (c < 10 && c >= 5)
    {
        (c = c - 5);
        n ++;
    }
    while (c < 5 && c >= 1)
    {
        (c = c - 1);
        n ++;
    }
    
    printf("%i\n", n);
}