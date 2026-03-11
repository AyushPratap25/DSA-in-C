/* Merge Sort via an array */
#include <stdio.h>

void mergeSort(int arr1[], int arr2[], int arr3[], int size1, int size2)
{
    int i = 0, j = 0;
    int k = 0;

    while (i <= size1 - 1 && j <= size2 - 1)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    while (i <= size1 - 1)
        arr3[k++] = arr1[i++];
    while (j <= size2 - 1)
        arr3[k++] = arr2[j++];
}

void display(int arr3[], int size3)
{
    for (int i = 0; i < size3; i++)
        printf("%d ", arr3[i]);
    printf("\n");
}

int main()
{
    int arr1[] = {1, 4, 7, 8, 12, 18};
    int arr2[] = {2, 3, 5, 9, 11};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int size3 = size1 + size2;
    int arr3[size3];

    mergeSort(arr1, arr2, arr3, size1, size2);
    display(arr3, size3);

    return 0;
}