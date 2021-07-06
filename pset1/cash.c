#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    double change;
    int coins = 0;

    // Prompt for change
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);

    while (change > 0)
    {
        change = roundf(change * 100) / 100;

        // Count the coins
        if(change > 0)
            coins++;

        // Subtract every possible quarter
        if (change >= 0.25)
            change = change - 0.25;

        // Subtract every possible dime
        else if (change >= 0.10)
            change = change - 0.10;

        // Subtract every possible nickel
        else if (change >= 0.05)
            change = change - 0.05;

        // Subtract every possible pennie
        else
            change = change - 0.01;
    }

    // Print number how many coins were used
    printf("%i\n", coins);
}