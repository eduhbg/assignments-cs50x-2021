#include <cs50.h>
#include <stdio.h>

const int LENGTH = 16;

// Verify the type of the credit card and show to user a output
void validateCreditCardNumber(int creditCardArray[], int count, int creditCardTotal)
{
    // Divide the creditCardTotal to get each digit separede
    int sliceTotal[2];
    sliceTotal[1] = creditCardTotal % 10;
    sliceTotal[0] = creditCardTotal /= 10;

    // Verify if the final digit is 0, if is, it is that is possible that the credit card is valid
    // American Express: 15 digits and starts with 34 or 37
    if (sliceTotal[1] == 0 && count == 15 && (creditCardArray[1] == 3 && (creditCardArray[2] == 4 || creditCardArray[2] == 7)))
    {
        printf("AMEX\n");
    }
    // Mastercard: 16 digits and the start range is 51 - 55
    else if (sliceTotal[1] == 0 && count == 16 && (creditCardArray[1] == 5 && (creditCardArray[2] >= 1 && creditCardArray[2] <= 5)))
    {
        printf("MASTERCARD\n");
    }
    // Visa: 13 or 16 digits and starts with 4
    else if (sliceTotal[1] == 0 && (count == 13 || count == 16) && creditCardArray[1] == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

void calculateCreditCardNumber(int creditCardArray[], int count)
{
    int multiplicableNumbers[2];
    int creditCardTotal = 0;
    int multiplyIndex = 0;

    // Multiply every digit by 2, starting with the number’s second-to-last digit
    for (int j = count - 1; j > 0; j -= 2)
    {
        multiplyIndex = creditCardArray[j] * 2;

        if(multiplyIndex > 9)
        {
            multiplicableNumbers[1] = multiplyIndex % 10;
            multiplicableNumbers[0] = multiplyIndex /= 10;
            creditCardTotal += multiplicableNumbers[0] + multiplicableNumbers[1];
        }
        else
        {
            creditCardTotal += multiplyIndex;
        }
    }

    // Sum the digits starting in position one and skipping two positions
    for (int i = count; i > 0; i -= 2)
    {
        creditCardTotal += creditCardArray[i];
    }

    // Call a final function that validates the credit card
    validateCreditCardNumber(creditCardArray, count, creditCardTotal);
}

// Transform credit card number into array and reverse it
void transformInputIntoArray(long creditCard)
{
    int basicArray[LENGTH];
    int creditCardArray[LENGTH];
    int count = 0;
    int result;

    do
    {
        // Extract the last digit of creditCard and put in the variable result
        result = creditCard % 10;

        // Put the last digit in basicArray
        basicArray[count] = result;

        // Divide the creditCard by 10 to get next last digit
        creditCard /= 10;

        count++;

    } while (creditCard != 0);

    // Reverse the position of array
    int j = 0;
    for (int i = count; i >= 0; i--)
    {
        creditCardArray[j] = basicArray[i];
        j++;
    }

    // Call a function that makes the math to validate the credit card
    calculateCreditCardNumber(creditCardArray, count);
}

int main(void)
{
    // Get the credit card number from the user
    long creditCard = get_long("What's your credit card number? Type just the numbers!\n");

    // Call a function to transform the credit card number into array
    transformInputIntoArray(creditCard);
}