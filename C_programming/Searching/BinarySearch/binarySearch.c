// Binary Search on an array
#include <stdio.h>

int binarySearch(int arr[], int n, int item)
{
    int low = 0;      // lowest index
    int high = n - 1; // highest index -> of subarray
    while (low <= high)
    {
        int mid = (low + high) / 2; // mid value of the array
        if (arr[mid] == item)
            return mid; // index
        else if (arr[mid] > item)
            high = mid - 1; // excluding mid
        else
            low = mid + 1; // excluding mid
    }

    return -1; // for not found 
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12};

    int index = binarySearch(arr, 6, 8);
    printf("Index: %d", index);

    return 0;
}