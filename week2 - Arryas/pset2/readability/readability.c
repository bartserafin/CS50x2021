#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt user for text
    string text_1 = get_string("Text: ");

    // Count letters
    int letters = count_letters(text_1);

    // Count words
    int words = count_words(text_1);

    // Count sentences
    int sentences = count_sentences(text_1);

    // Display letters, words, sentences
    // printf("Letters %i\n", letters);
    // printf("Words %i\n", words);
    // printf("Sentences %i\n", sentences);

    // Compute The Coleman-Liau index
    float l = letters * 100.0 / words;
    float s = sentences * 100.0 / words;
    int index = round(0.0588 * l - 0.296 * s - 15.8);

    // Display Grade
    if (index <= 1)
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

int count_letters(string text)
{
    int n = strlen(text);
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            counter += 1;
        }
    }
    return counter;
}

int count_words(string text)
{
    int n = strlen(text);
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (text[i] == ' ')
        {
            counter += 1;
        }
    }
    counter += 1;
    return counter;
}

int count_sentences(string text)
{
    string marks = "!.?";
    int n = strlen(text);
    int m = strlen(marks);
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (text[i] == marks[j] && text[i + 1] != '.')
            {
                counter += 1;
            }
        }
    }
    return counter;
}