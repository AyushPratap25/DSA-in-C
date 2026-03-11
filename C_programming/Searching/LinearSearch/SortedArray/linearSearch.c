// Linear Search when array is sorted
#include <stdio.h>

int linearSearch(int arr[], int n, int item)
{
    int i = 0;
    while (i < n && arr[i] < item)
        i++;
    if (arr[i] == item)
        return i;
    return -1; // failed
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10};

    int index = linearSearch(arr, 6, 7);
    printf("Index : %d", index); // -1 failed -> not found in the array
    return 0;
}