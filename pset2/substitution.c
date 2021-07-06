#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // If the user do not type any input, show this message
    if (argc == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        int length = strlen(argv[1]);

        // Check the lenght of the argv
        if (length < 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

        //Check each character inside of argv
        for (int i = 0; i < length; i++)
        {
            int asciiChar = argv[1][i];

            if (asciiChar < 65 || (asciiChar > 90 && asciiChar < 97) || asciiChar > 122)
            {
                printf("Type just letters.\n");
                return 1;
            }

            for (int j = i + 1; j < length; j++)
            {
                if (isupper(argv[1][i]))
                {
                    int compareAsciiChar = toupper(argv[1][j]);

                    if (asciiChar == compareAsciiChar)
                    {
                        printf("Key must not contain repeated characters.\n");
                        return 1;
                    }
                }
                else
                {
                    int compareAsciiChar = tolower(argv[1][j]);

                    if (asciiChar == compareAsciiChar)
                    {
                        printf("Key must not contain repeated characters.\n");
                        return 1;
                    }
                }
            }
        }

        // Get the text of the user to encrypt
        string plaintext = get_string("plaintext: ");
        string ciphertext = plaintext;

        // Define a alphabet with the same length of cipher keys
        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        // Compare each ASCII number of the plaintext with alphabet
        // Use the index of alphabet to get the same index of cipher keys (argv)
        // Get the correct index and change the ciphertext character to cipher key (argv)
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            int asciiPlainText = plaintext[i];

            for (int j = 0, alphabetLenght = strlen(alphabet); j < alphabetLenght; j++)
            {
                int asciiAlphabet = alphabet[j];

                if (asciiPlainText == asciiAlphabet + 32)
                {
                    ciphertext[i] = tolower(argv[1][j]);
                }
                else if (asciiPlainText == asciiAlphabet)
                {
                    ciphertext[i] = toupper(argv[1][j]);
                }
            }
        }

        // Show the ciphertext encrypt as result
        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }
}