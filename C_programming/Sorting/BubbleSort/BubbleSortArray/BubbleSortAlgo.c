/* remember var declaration in for loop is not 
accepted by older compilers.
To make it universal declare at the top 
*/

#include <stdio.h>
#define MAX 5

int main()
{
    int arr[MAX] = {5, 3, 122, 8, 4};

    for (int i = 0; i < MAX - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < (MAX - 1 - i); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;

    }

    printf("\n");
    for (int i = 0; i < MAX; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");

    return 0;
}