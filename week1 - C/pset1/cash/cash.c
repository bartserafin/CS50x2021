#include <stdio.h>
#include <cs50.h>
#include <math.h>

// # quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢)
// # given a float in dollars, return the least possible number of coins to add up to that float

// # Example
// # Change owed: 0.41
// # 4


int main(void)
{

    float change = 0;
    int count_coin = 0;
    float cash = 0;
    int count_all_coins = 0;

// Prompt user for a change
    do
    {
        change = get_float("Change: ");
    }
    while (change < 0);

    int change_left = round(change * 100);

    while (cash < change)
    {
        while (change_left >= 25)
        {
            count_coin = floor(change_left / 25); // 41//25 = 1
            cash = count_coin * 25; // 25
            count_all_coins += count_coin; // 1
            change_left -= cash; // 41 - 25 = 16
        }
        while (change_left >= 10)
        {
            count_coin = floor(change_left / 10); // 16//10 = 1
            cash = count_coin * 10; // 10
            count_all_coins += count_coin; // 2
            change_left -= cash; // 16 - 10 = 6
        }
        while (change_left >= 5)
        {
            count_coin = floor(change_left / 5); // 6//5 = 1
            cash = count_coin * 5; // 5
            count_all_coins += count_coin; // 3
            change_left -= cash; // 6 - 5= 1
        }
        while (change_left >= 1)
        {
            count_coin = floor(change_left / 1);
            cash = count_coin * 1;
            count_all_coins += count_coin;
            change_left -= cash;
        }
        printf("Coins: %i", count_all_coins);
    }
}