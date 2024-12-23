#include <cs50.h>
#include <stdio.h>

void print_row(int length);
void print_space(int space);

int main(void)
{
    int num = get_int("How tall the pyramids should be? ");
    while (num <= 0)
    {
        num = get_int("How tall the pyramids should be? ");
    }

    for (int i = 0; i < num; i++)
    {
        print_space(num - i);
        print_row(i + 1);
    }
}

void print_row(int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("#");
    }
    printf("\n");
}

void print_space(int space)
{
    for (int i = 1; i < space; i++)
    {
        printf(" ");
    }
}
