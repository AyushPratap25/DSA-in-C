#include <stdio.h>

int power(int a, int n)
{
    if (n == 0)
        return 1;
    return (a * power(a, n - 1)); // a * a^(n - 1)
}

int main()
{
    printf("%d", power(3, 5));
    return 0;
}