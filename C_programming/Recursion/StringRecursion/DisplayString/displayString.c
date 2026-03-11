#include <stdio.h>

void display(char *str)
{
    if (*str == '\0')
        return;
    printf("%c", *str);
    display(1 + str); // move to next address
}

int main()
{
    char str[] = "Hello World";
    display(str);

    return 0;
}