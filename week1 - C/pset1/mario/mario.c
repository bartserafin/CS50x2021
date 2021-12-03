#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
//promt user for height
    do
    {
        n = get_int("Height: ");

    }
    while (n >= 9 || n <= 0);
//prints both sides of pyramid of height
    for (int i = 0; i < n; i++)
    {
        for (int x=n-2; x >= i; x--)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");

        for (int a = 0; a <= i; a++)
        {
            printf("#");
        }
        printf("\n");
    }
}
