#include <stdio.h>
#include <stdlib.h>

struct sll
{
    int val;
    struct sll *next;
};

int main()
{
    // your code here
    return 0;
}

// Node count 
int Nodecount(struct sll *head)
{
    struct sll *curr = head;
    int count = 0;

    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }

    return count;
}
