#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int size)
{
    if (size <= 0)
        return;
    
    int flag = 1;
    while (flag == 1)
    {
        flag = 0;
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
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
    int arr[5] = {3, 1, 5, 2, 6};
    bubbleSort(arr, 5);
    display(arr, 5);

    return 0;
}