#include <cs50.h>
#include <stdio.h>

// Function to print the amount of hashes
void printHashes(int hashAmount, int height)
{
    string hash = "#";

    if (hashAmount <= height)
    {
        for (int k = 0; k < hashAmount; k++)
        {
            printf("%s", hash);
        }
    }
}

int main(void)
{
    int height;
    int hashAmount = 1;
    string space = " ";

    // Get the height value from user
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Create the amount of space for the first hash
    int decreaseSpaces = height - 1;

    // Print the pyramid
    for (int i = 0; i < height; i++)
    {

        for (int j = decreaseSpaces; j > 0; j--)
        {
            printf("%s", space);
        }

        // Call a function to print hashes
        printHashes(hashAmount, height);

        printf("\n");
        decreaseSpaces--;
        hashAmount++;
    }
}