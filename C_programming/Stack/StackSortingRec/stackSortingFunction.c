#include <stdio.h>

int main() {
    // your code here
    return 0;
}

// Helper: insert an element into sorted stack
void sortedInsert(int x) {
    // If stack is empty OR top element is smaller, push directly
    if (isEmpty() || x > peek()) {
        push(x);
        return;
    }

    // Otherwise pop the top and recurse
    int temp = pop();
    sortedInsert(x);

    // Put the popped element back
    push(temp);
}

// Function: sort the whole stack
void sortStack() {
    if (!isEmpty()) {
        // Remove the top element
        int x = pop();

        // Sort the remaining stack
        sortStack();

        // Insert the popped element in sorted order
        sortedInsert(x);
    }
}
