#include <stdio.h>

int length(char *str)
{
    if (*str == '\0')
        return 0;
    return (1 + length(str + 1)); 
}

int main()
{
    char str[] = "ABcdef";
    printf("length : %d", length(str));
    return 0;
}