/* QUESTION:
How do you find the sum of all the natural number below a given limit that are multiples of 3 or 5? */

// ANSWER:
// 1. SUM OF ALL NATURAL NUMBER MEANS RESULT OF 1+2+3+4+5....n
// 2. BELOW A GIVEN NUMBER MEANS IF THE NUMBER IS n THEN LAST ADDING SUM NUMBER WILL BE n-1
// 3. MULTIPLES OF 3 OR 5 MEANS  THE SUM NUMBER SHOULD BE DEVIDED BY 3 OR 5. MEANS THE MODULO(%) SHOULD BE 0.

#include <stdio.h>
long long sum_of_multiples(long long n, long long k)
{
    long long p = (n - 1) / k;
    /* This formula answers one simple question:
    How many multiples of k exist strictly below the limit n.
    Let’s use real numbers.
    Assume your limit is n = 10, and
    you want to find the multiples of k = 3.
    The multiples of 3 below 10 are: 3, 6, and 9.
    There are exactly 3 terms.
    Now plug it into the formula:
    p = (10 - 1) / 3
      = 9 / 3
      3
    what if the n = 11?
   p = (11 - 1) / 3
     = 10 / 3
     = 3..3333
    in c it will drop the .333. So p = 3
    But in math we have to use floor symbol*/
    return k * (p * (p + 1)) / 2;
    /* This line calculates the actual sum instantly.
     Let's look at why it works using example where we are adding 3 + 6 + 9. (n = 10)
     If you look closely, every number in that sequence shares a common factor of 3 (which is k).
     If you factor out the 3, the sequence looks like this:
     3 * (1 + 2 + 3)
     Look at the part inside the parentheses:
     (1 + 2 + 3) : This is just the sum of consecutive natural numbers up to p (where p = 3)
     There is a famous mathematical rule for finding the sum of 1 + 2 + 3 + ... + p.
     The formula is:
     Sum = p * (p + 1) / 2
     So, to find the sum of your multiples, you calculate the sum of that basic
     1 + 2 + 3 sequence, and then multiply the whole thing by k (which is 3).
     Total Sum = k * (p * (p + 1)) / 2
     That is precisely what return k * (p * (p + 1)) / 2 does.
     It calculates the answer in one single mathematical operation,
     bypassing the need for a slow,
     repetitive for loop.*/
}
int main(void)
{
    long long n, sum_loop;
    printf("-----------------------------------------------------------------------------------\n\n");
    printf("This program will find all natural number below a given limit that are multiples of 3 or 5\n-----------------------------------------------------------------------------------\n\nPlease enter the limit: ");
    if (scanf("%lld", &n) != 1 || n < 1)
    {
        printf("--------------------------------------------------\nPlease enter a valid positive integer");
        return 1;
    }
    printf("-----------------------------------------------------------------------------------\n\n");
    sum_loop = 0;
    for (int i = 1; i < n; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum_loop += i;
        }
    }
    printf("The sum:\n");
    printf("using loop : %lld;\n", sum_loop);
    // now let's solve it mathematically
    long long sum_math = sum_of_multiples(n, 3) + sum_of_multiples(n, 5) - sum_of_multiples(n, 15);
    printf("using math: %lld;", sum_math);
    printf("\n-----------------------------------------------------------------------------------\n\n\n");
    return 0;
}