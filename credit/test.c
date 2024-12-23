#include <cs50.h>
#include <stdio.h>

int main(void){
    long number = get_long("Number: ");
    long check2 = number;
    int sum1 = 0;
    int sum2 = 0;
    int mod1,mod2,d1,d2;
    while(check2>0){
        mod1 = check2 % 10;
        check2 = check2/10;
        mod2 = check2%10;
        check2 = check2/10;
        sum1 = sum1 + mod1;
        mod2 = mod2*2;
        d1 = mod2 %10;
        d2 = mod2 /10;
        sum2 = sum2 + d1 + d2;
    }
    printf("sum1:%i\n",sum1);
    printf("sum2:%i\n",sum2);
    printf("total:%i\n",sum1+sum2);
}
