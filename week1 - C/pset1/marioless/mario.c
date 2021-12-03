#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
// prompt user for height
    do
    {
        n = get_int("Height: ");

    }
    while (n >= 9 || n <= 0);
// prints left-hand side of pyramid of
    for (int i = 0; i < n; i++)
    {
        for (int x = n - 2; x >= i; x--)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
