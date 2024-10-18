#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void FindMinAndSwap (int arr[], int size_of_array, int left);

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

    FindMinAndSwap(nums, size, 0);

    for (int i = 0; i < size; i++) {printf("%i ", nums[i]);};

    free(nums);

    return 0;
}

void FindMinAndSwap (int arr[], int size_of_array, int left)
{   
    if (left == size_of_array - 1)
    {
        return;
    }    
    
    int reduced_size = size_of_array - left;

    int index = left;

    int min = arr[left];

    for (int i = left; i < size_of_array; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];

            index = i;
        }
    }

    if (index !=  left)
    {
        int temp = arr[left];

        arr[left] = arr[index];

        arr[index] = temp;

    }

    FindMinAndSwap(arr, size_of_array, left + 1);
}
