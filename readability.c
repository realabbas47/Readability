#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// functions used
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // User input
    string text = get_string("Text: ");

    // counting all the values needed
    int total_letters = count_letters(text);
    int total_words = count_words(text);
    int total_sentences = count_sentences(text);

    // calculating grade
    float L = (total_letters * 1.00 / total_words * 1.00) * 100;
    float S = (total_sentences * 1.00 / total_words * 1.00) * 100;
    int index = (int)round((0.0588 * L) - (0.296 * S) - 15.8);

    // Printing result
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
    return 0;
}

// Count the total number of letters in a text
int count_letters(string text)
{
    int letters = 0;
    int textlenth = strlen(text);
    for (int i = 0; i < textlenth; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

// Count the number of words in a text
int count_words(string text)
{
    int a = 0;
    int b = 32;
    int words = 1;
    int textlenth = strlen(text);
    for (int i = 0; i < textlenth; i++)
    {
        a = text[i];
        if (a == b)
        {
            words++;
        }
    }
    return words;
}

// Counts the number of sentences in the text
int count_sentences(string text)
{
    int a = 0;
    int b = 33;
    int c = 46;
    int d = 63;
    int sentences = 0;
    int textlenth = strlen(text);
    for (int i = 0; i < textlenth; i++)
    {
        a = text[i];
        if (a == b || a == c || a == d)
        {
            sentences++;
        }
    }
    return sentences;
}