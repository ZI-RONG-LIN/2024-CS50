#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int point[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(string word);

int main(void)
{
    string player_1 = get_string("Player 1: ");
    string player_2 = get_string("Player 2: ");
    int score_1 = compute_score(player_1);
    int score_2 = compute_score(player_2);

    if (score_1 > score_2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score_1 < score_2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int score = 0;
    for (int i = 0, length = strlen(word); i < length; i++)
    {
        if (isupper(word[i]))
        {
            score += point[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += point[word[i] - 'a'];
        }
    }
    return score;
}
