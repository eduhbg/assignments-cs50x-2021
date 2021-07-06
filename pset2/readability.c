#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int coleman_liau_formula(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("Text: ");

    int totalLetters = count_letters(text);
    int totalWords = count_words(text);
    int totalSentences = count_sentences(text);

    int index = coleman_liau_formula(totalLetters, totalWords, totalSentences);

    // Condition to show what type of grade the text belongs
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int coleman_liau_formula(int letters, int words, int sentences)
{
    // L is the average number of letters per 100 words in the text
    float l = (letters / (float) words) * 100;

    // S is the average number of sentences per 100 words in the text
    float s = (sentences / (float) words) * 100;

    // Coleman-Liau formula calculation
    int result = round(0.0588 * l - 0.296 * s - 15.8);

    return result;
}


// Calculates the number of sentences in the text
int count_sentences(string text)
{
    int count = 0;

    // "?", "!" and "." in ASCII numbers is 63, 33 and 46
    for (int i = 0, length = strlen(text); i <= length; i++)
    {
        int asciiChar = text[i];

        if (asciiChar == 33 || asciiChar == 46 || asciiChar == 63)
        {
            count++;
        }
    }

    return count;
}

// Calculates the number of spaces between words to indicate how many words are in the text
int count_words(string text)
{
    int count = 1;

    // "space" is 32 in ASCII numbers
    for (int i = 0, length = strlen(text); i <= length; i++)
    {
        int asciiChar = text[i];

        if (asciiChar == 32)
        {
            count++;
        }
    }

    return count;
}

// Calculates the number of letters in the text
int count_letters(string text)
{
    int count = 0;

    for (int i = 0, length = strlen(text); i <= length; i++)
    {
        int asciiChar = text[i];

        if ((asciiChar >= 65 && asciiChar <= 90) || (asciiChar >= 97 && asciiChar <= 122))
        {
            count++;
        }
    }

    return count;
}