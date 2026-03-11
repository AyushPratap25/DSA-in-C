#include <stdio.h>

void decToBin(int n)
{
    if (n == 0)
    {
        printf("0");
        return;
    } 
    decToBin(n / 2); // recursive call 
    printf("%d", n % 2); // remainder
}

int main() {
    decToBin(12);
    return 0;
}