#include <stdio.h>
#include <stdlib.h>

struct sll
{
    int data;
    struct sll *next;
};
// function prototype
void bubbleSortSll(struct sll *head);

int main()
{
    return 0;
}

// bubble sort
void bubbleSortSll(struct sll *head)
{
    if (head == NULL)
    {
        printf("List is empty!!\n");
        return;
    }

    struct sll *last = NULL;
    int swapped;
    do
    {
        swapped = 0;
        struct sll *curr = head;
        while (curr->next != last)
        {
            if (curr->data > curr->next->data)
            {
                int temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
                swapped = 1;
            }
            curr = curr->next;
        }
        last = curr;
    } while (swapped);
}
