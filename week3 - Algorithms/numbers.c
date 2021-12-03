#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int numbers[] = {4, 6, 8, 2, 7, 5, 0};

    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == 0)
        {
            printf("Found.");
            return 0;
        }
    }
    printf("Not found.");
    return 1;
}