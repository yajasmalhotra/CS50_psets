#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What is your name?\n"); //asks user for their name
    printf("Hello, %s\n", name);
}