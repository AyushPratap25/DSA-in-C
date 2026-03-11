#include <stdio.h>
#include <stdlib.h> // needed for malloc

struct poly {
    int coeff;
    int pow;
    struct poly *next;
};

// function prototypes
struct poly *createNode(int c, int p);
struct poly *insert_Item(struct poly *head, int c, int p);
void printPoly(struct poly *head);

int main() {
    struct poly *head = NULL;

    head = insert_Item(head, 5, 2); // 5x^2
    head = insert_Item(head, 3, 1); // 3x^1
    head = insert_Item(head, 2, 0); // 2

    printPoly(head);

    return 0;
}

struct poly *createNode(int c, int p) {
    struct poly *newNode = malloc(sizeof(struct poly));
    if (newNode == NULL) {
        printf("Memory allocation failed!!\n");
        return NULL;
    }

    newNode->coeff = c;
    newNode->pow = p;
    newNode->next = NULL;

    return newNode;
}

struct poly *insert_Item(struct poly *head, int c, int p) {
    struct poly *newNode = createNode(c, p);
    if (head == NULL) {
        return newNode;
    }

    struct poly *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;

    return head;
}

void printPoly(struct poly *head) {
    struct poly *curr = head;
    while (curr != NULL) {
        printf("%dx^%d", curr->coeff, curr->pow);
        if (curr->next != NULL)
            printf(" + ");
        curr = curr->next;
    }
    printf("\n");
}
