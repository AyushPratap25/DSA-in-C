// Bubble sort algorithm
#include <stdio.h>
#define MAX 5

// sorting
void bubbleSort(int arr[], int size)
{
    int i, j, swapped; 
    for (i = 0; i < (size - 1); i++) // no. of passes
    {
        swapped = 0;
        for (j = 0; j < (size - 1 - i); j++) // comparing elements pairwise (-i) for decrementing the no. of loop next time
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swapped = 1;
            }
        }
        if (!swapped) return; // end if no swap happens in one pass
    }
}

// input function
void inputArr(int arr[], int size)
{
    // input
    int i = 0;
    printf("Enter %d elements: ", size);
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

// display
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[MAX];
    int i;
    
    inputArr(arr, MAX);

    bubbleSort(arr, MAX);
    // Output
    printf("Sorted : ");
    display(arr, MAX);

    return 0;
}

