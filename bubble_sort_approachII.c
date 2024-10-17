#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void bubbleSort (int arr[], int right);

int main (int argc, char* argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    int size = atoi(argv[1]);

    int *nums = malloc(size * sizeof(int));

    if (nums == NULL)
    {
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        scanf("%i", &nums[i]);
    }

    bubbleSort(nums, size);

    for (int i = 0; i < size; i++)
    {
        printf("%i ", nums[i]);
    }

    free(nums);

    return 0;
}

void bubbleSort (int arr[], int right)
{
    if (right == 1)
    {
        return;
    }

    for (int i = 0; i < right - 1; i++)
    {
        if (arr[i] > arr[i+1])
        {
            int temp = arr[i];

            arr[i] = arr[i + 1];

            arr[i + 1] = temp;
        }
    }

    bubbleSort(arr, right - 1);

}