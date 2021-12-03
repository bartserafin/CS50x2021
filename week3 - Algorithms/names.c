#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"};

    for (int i = 0; i < 7; i++)
    {
        if (strcmp(names[i], "Ron") == 0) // string compare, return 3 possible values - 0 - match, >0 names should be before searched name,
        // <0 name should be after the search name. This converts letters to ASCI code, and then checks if the same is on both sides
        {
            printf("Found");
            return 0;
        }
    }
    printf("Not found\n.")
    return 1;
}