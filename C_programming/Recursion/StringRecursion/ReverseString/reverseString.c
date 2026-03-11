#include <stdio.h>

void revDisplay(char *str)
{
    if (*str == '\0')
        return;
    revDisplay(1 + str);
    printf("%c", *str);
}

int main()
{
    char str[] = "Hello";
    revDisplay(str);
    return 0;
}