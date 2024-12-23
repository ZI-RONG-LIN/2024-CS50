#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letter(string text);
int count_space(string text);
int count_sentence(string text);

int main(void)
{
    string input = get_string("Text: ");
    int letter = count_letter(input);
    int words = count_space(input) + 1;
    int sentence = count_sentence(input);
    float L = ((float) letter / (float) words) * 100;
    float S = ((float) sentence / (float) words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letter(string text)
{
    int letter = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letter += 1;
        }
    }
    return (letter);
}

int count_space(string text)
{
    int space = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isspace(text[i]))
        {
            space += 1;
        }
    }
    return (space);
}

int count_sentence(string text)
{
    int sentence = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence += 1;
        }
    }
    return (sentence);
}
