#include <stdio.h>
#include <stdlib.h>

#define MAX 100   // maximum stack size

int stack[MAX];
int top = -1;

// ---------- Stack operations ----------
int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

void push(int x) {
    if (isFull()) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (isEmpty()) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (isEmpty()) {
        printf("Stack empty!\n");
        return -1;
    }
    return stack[top];
}

// ---------- Sorting functions ----------
void sortedInsert(int x) {
    if (isEmpty() || x > peek()) {
        push(x);
        return;
    }

    int temp = pop();
    sortedInsert(x);
    push(temp);
}

void sortStack() {
    if (!isEmpty()) {
        int x = pop();
        sortStack();
        sortedInsert(x);
    }
}

// ---------- Utility ----------
void printStack() {
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

// ---------- Main ----------
int main() {
    int n, val;

    printf("Enter number of elements in stack: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Too many elements! Max allowed = %d\n", MAX);
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }

    printf("\nOriginal stack (top to bottom): ");
    printStack();

    sortStack();

    printf("Sorted stack (top to bottom):   ");
    printStack();

    return 0;
}
