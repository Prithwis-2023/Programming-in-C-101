#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void QuickSort (int arr[], int left, int right);

int main (int argc, char *argv[])
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

    for (int i = 0; i < size; i++) {scanf("%i", &nums[i]);};

    QuickSort(nums, 0, size - 1);

    for (int i = 0; i < size; i++) {printf("%i ", nums[i]);};

}

void QuickSort (int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int pivot = arr[right];
    
    int partitionIndex = left - 1;

    for (int j = left; j <= right; j++)
    {
        if (arr[j] <= pivot)
        {
            partitionIndex++;

            int temp = arr[j];

            arr[j] = arr[partitionIndex];

            arr[partitionIndex] = temp;
        }
    }

    QuickSort(arr, left, partitionIndex - 1);

    QuickSort(arr, partitionIndex + 1, right);

}