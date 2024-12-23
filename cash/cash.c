#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int money = get_int("Change owed: ");
    while (money <= 0)
    {
        money = get_int("Change owed: ");
    }
    int count_25 = money / 25;
    int count_10 = (money - count_25 * 25) / 10;
    int count_5 = (money - count_25 * 25 - count_10 * 10) / 5;
    int count_1 = (money - count_25 * 25 - count_10 * 10 - count_5 * 5) / 1;
    printf("%i\n", count_25 + count_10 + count_5 + count_1);
}
