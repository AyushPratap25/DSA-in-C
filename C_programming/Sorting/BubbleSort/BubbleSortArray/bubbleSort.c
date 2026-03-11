// Bubble sort algorithm
#include <stdio.h>
#define MAX 5

// sorting
void bubbleSort(int arr[], int n)
{
    int i, j, flag; 
    for (i = 0; i < (n - 1); i++) // no. of passes
    {
        flag = 0;
        for (j = 0; j < (n - 1 - i); j++) // comparing elements pairwise (-i) for decrementing the no. of loop next time
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                flag = 1;
            }
        }
        if (!flag) return; // end if no swap happens in one pass
    }
}

// input function
void inputArr(int arr[], int n)
{
    // input
    int i = 0;
    printf("\n\nEnter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}



int main()
{
    int arr[MAX];
    int i;

    // input call
    inputArr(arr, MAX);

    // call
    bubbleSort(arr, MAX);

    // Output
    printf("\n\nSorted array:\t");
    for (i = 0; i < MAX; i++)
        printf("| %d ", arr[i]);

    return 0;
}
