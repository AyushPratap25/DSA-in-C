#include <stdio.h>

long long int fact(int n);

int main()
{
    printf("%lld", fact(5));
    return 0;
}

long long int fact(int n)
{
    if (n == 0)
        return 1;

    return (n * fact(n - 1));
}