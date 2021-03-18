#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int startSize;

    do
    {
        startSize = get_int("Start: \n");
    }
    while (startSize < 9);


    // Prompt for end size
    int endSize;

    do
    {
        endSize = get_int("End: \n");
    }
    while (endSize < startSize);

    // Calculate number of years until we reach threshold
    int numberOfYears = 0;

    if (startSize == endSize)
    {
        numberOfYears = 0;
    }
    else
    {
        while (startSize < endSize)
        {
            startSize = startSize + (int)(startSize / 3) - (int)(startSize / 4);
            numberOfYears++;
        }
    }

    // Print number of years
    printf("Years: %i\n", numberOfYears);
}