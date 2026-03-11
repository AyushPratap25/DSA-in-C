/* Selection Sort via an array */
#include <stdio.h>

void selectionSort(int arr[], int n)
{
    int min_index;
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        // Assume the current index is the minimum
        min_index = i;
        for (int j = i + 1; j < n; j++) // skipping self check via i + 1.
        {
            // Find the minimum element in the unsorted part
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        // Swap only if a smaller element is found
        if (min_index != i)
        {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {4, 1, 8, 7, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);
    display(arr, n);
    return 0;
}