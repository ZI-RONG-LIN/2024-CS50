#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");
    int i = 0;
    long check1 = number;
    long check2 = number;
    int sum1 = 0;
    int sum2 = 0;
    int mod1, mod2, d1, d2, total, s1, s2;
    while (check1 > 0)
    {
        check1 = check1 / 10;
        i++;
    }
    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
    }
    else
    {
        while (check2 > 0)
        {
            mod1 = check2 % 10;
            check2 = check2 / 10;
            mod2 = check2 % 10;
            check2 = check2 / 10;
            sum1 = sum1 + mod1;
            mod2 = mod2 * 2;
            d1 = mod2 % 10;
            d2 = mod2 / 10;
            sum2 = sum2 + d1 + d2;
        }
        // printf("sum1:%i\n",sum1);
        // printf("d1:%i\n",d1);
        // printf("sum2:%i\n",sum2);

        total = sum1 + sum2;
        // printf("total:%i\n",total);
        if (total % 10 != 0)
        {
            printf("INVALID\n");
        }
        else
        {

            long start = number;
            while (start > 100)
            {
                start = start / 10;
            }
            s1 = start / 10;
            s2 = start % 10;
            // printf("%i\n",s1);
            // printf("%i\n",s2);
            if (i == 13 && s1 == 4)
            {
                printf("VISA\n");
            }
            else if (i == 16 && s1 == 4)
            {
                printf("VISA\n");
            }
            else if ((i == 15) && (start == 34 || start == 37))
            {
                printf("AMEX\n");
            }
            else if (start >= 51 && start <= 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
}
