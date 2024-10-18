#include <stdio.h>

int main (void)
{
    int arr[] = {12, 29, 25, 8, 32, 17, 40};

    int size = sizeof(arr) / sizeof(int);

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                
                arr[i] = arr[j];
                
                arr[j] = temp; 
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%i ", arr[i]);
    }

    printf("\n");
}