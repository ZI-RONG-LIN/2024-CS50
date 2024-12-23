#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);
int Upper[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
               'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int Lower[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
               'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main(int argc, string argv[])
{
    if (argc != 2 || only_digits(argv[1]) != 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string plaintext = get_string("plaintext: ");
    int arg = atoi(argv[1]);
    printf("ciphertext: ");
    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        char ciphertext = rotate(plaintext[i], arg);
        printf("%c", ciphertext);
    }
    printf("\n");
}

bool only_digits(string s)
{
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (!isdigit(s[i]))
        {
            return 1;
        }
    }
    return 0;
}

char rotate(char c, int n)
{
    int num = n % 26;
    int c_rotate = 0;
    if (isupper(c))
    {
        c_rotate = ((int) Upper[(c - 'A' + (char) num) % 26]);
    }
    else if (islower(c))
    {
        c_rotate = ((int) Lower[(c - 'a' + (char) num) % 26]);
    }
    else if (!isalpha(c))
    {
        c_rotate = (int) c;
    }
    return (c_rotate);
}
