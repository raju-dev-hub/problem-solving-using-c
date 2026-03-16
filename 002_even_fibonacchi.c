// 2.	How can you calculate the sum of the even-valued terms in the Fibonacci sequence up to a certain limit?
#include <stdio.h>
int main(void)
{
    long long a = 0, b = 1, n, f = 0, sum = 0;
    printf("-----------------------------------------------------------------------------\n");
    printf("This program will calculate the sum of even fibonacchi terms  to a given limit.\n");
    printf("-----------------------------------------------------------------------------\n");    
    printf("Please enter the limit: ");
    if (scanf("%lld", &n) != 1 || n < 0)
    {
        printf("please enter a valid positive integer");
        printf("-----------------------------------------------------------------------------\n");
        return 1;
    }
    printf("-----------------------------------------------------------------------------\n\n");
    printf("Total sum of even-valued fibonacchi sequence up to %lld is:\n", n);
    while (1)
    {
        f = a + b;
        a = b;
        b = f;
        if (f > n)
            break;
        if (f % 2 == 0)
        {
            sum += f;
            printf("%lld + ", f);
        }
    }
    printf("\b\b= %lld\n", sum);
    printf("-----------------------------------------------------------------------------\n");
    return 0;
}