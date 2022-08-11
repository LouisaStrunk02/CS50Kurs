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
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float l = (float)letters / (float)words * 100;
    float s = (float)sentences / (float)words * 100;
    int grade = round(0.0588 * l - 0.296 * s - 15.8);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade: %i\n", grade);
    }
}

int count_letters(string text)
{
    int numberofletters = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            numberofletters += 1;
        }
    }

    return numberofletters;
}

int count_words(string text)
{
    int numberofwords = 1;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == ' ')
        {
            numberofwords += 1;
        }
    }

    return numberofwords;
}

int count_sentences(string text)
{
    int numberofsentences = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            numberofsentences += 1;
        }
    }

    return numberofsentences;
}
