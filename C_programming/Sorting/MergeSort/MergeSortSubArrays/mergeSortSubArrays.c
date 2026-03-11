#include <stdio.h>

void mergeSort(int arr[], int low1, int up1, int low2, int up2)
{
    // int temp[low1 + up2]; bug
    int temp[(up1 - low1 + 1) + (up2 - low2 + 1)]; // if low!=0 above line fails for no. of elements
    int i = low1, j = low2;
    int k = 0;
    while (i <= up1 && j <= up2)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= up1)
        temp[k++] = arr[i++];
    while (j <= up2)
        temp[k++] = arr[j++]; // at final, last element inserted and k++ resulting k = no.of elements, rather than top index.

    for (int m = 0; m < k; m++) // k provides no. of elements merged
    {   // helpful in partial array sorting
        arr[low1 + m] = temp[m]; // if low1 is not 0
    }
}

void display(int arr3[], int size3)
{
    for (int i = 0; i < size3; i++)
        printf("%d ", arr3[i]);
    printf("\n");
}

int main()
{
    int arr1[] = {1, 4, 7, 8, 2, 5, 6, 9};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    mergeSort(arr1, 0, 3, 4, 7);
    display(arr1, size1);

    return 0;
}