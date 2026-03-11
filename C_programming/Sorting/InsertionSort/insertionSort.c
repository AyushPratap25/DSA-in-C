/* Insertion Sort via an array */
#include <stdio.h>

void insertionSort(int arr[], int size)
{
    int j;
    int key;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        // while loop
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // swapp
            j--;
        }

        arr[j + 1] = key;
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {4, 1, 8, 2, 10, 15, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);

    display(arr, size);

    return 0;
}


void insertionSort(int arr[], int size)
{
    int j;
    int key;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        // while loop
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j]; // swapp
            }
        }

        arr[j + 1] = key;
    }
}
