/* Adding 3rd node to the linked list without using extra space(or say pointer) */
/* Note that here struct sll *next is just a pointer of struct sll type pointing to it.
its work is to just store the address of next node that's it nothing else it does,
that also we actually make it store by providing head->next = curr where curr is the node
after head so its address gets stored in the head->next.

Now the answer to the quesiton that how the pointer jumps from one node to the other is that
let say we store the address of a node in struct sll *temp = head
now while trying to traverse when temp = temp->next in that case temp contains the address of
the next node then after that when we try to do like temp->value actually its *p.value
means point to the address stored in p and thats the address of the struct and as we know
like to fetch the value of the struct we use the dot operator in reality the the *p gets hidden
behind the arrow "->" and makes creates confusing thinkin it to be as p but in actual it is
*p  */

/* head, curr are just a piece of block containg the address of the head node the starting
and the curr containing the address of the 2 node its a pointe remember this */

#include <stdio.h>
#include <stdlib.h>

// struct of linked list
struct sll
{
    int val;
    struct sll *next;
};

int main()
{
    struct sll *head = NULL, *curr = NULL;

    // head node
    head = (struct sll *)malloc(sizeof(struct sll));
    if (head == NULL)
    {
        printf("\nMemory allocation failed\n");
        exit(0);
    }
    head->val = 23;
    head->next = NULL;

    // curr node
    curr = (struct sll *)malloc(sizeof(struct sll));
    if (curr == NULL)
    {
        printf("\nMemory allocation failed\n");
        exit(0);
    }
    curr->val = 32;
    curr->next = NULL;

    // linking head and curr node
    head->next = curr;

    // adding 3rd node wihtout using extra pointer
    curr = (struct sll *)malloc(sizeof(struct sll));
    if (curr == NULL)
    {
        printf("\nMemory allocation failed\n");
        exit(0);
    }
    curr->val = 12;
    curr->next = NULL;

    // linking last 2nd node (say previous curr node with new curr)
    head->next->next = curr;

    // printing the list
    struct sll *temp = head;
    while (temp != NULL)
    {
        printf(" %d ", temp->val);
        temp = temp->next;
    }

    return 0;
}