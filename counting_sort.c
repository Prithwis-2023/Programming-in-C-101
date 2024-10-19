#include <stdio.h>
#include <stdlib.h>

int count_occurences(int arr[], int size, int n);

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

    int max = nums[0];

    for (int i = 0; i < size; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }

    int *counts = malloc((max + 1) * sizeof(int));

    if (counts == NULL)
    {
        return 1;
    }

    int *counts_cumulative = malloc((max + 1) * sizeof(int));

    if (counts_cumulative == NULL)
    {
        return 1;
    }

    for (int i = 0; i <= max; i++) 
    {
        counts[i] = count_occurences(nums, size, i);
    }

    counts_cumulative[0] = counts[0];

    for (int i = 1; i <= max; i++) 
    {
        counts_cumulative[i] = counts_cumulative[i - 1] + counts[i];
    }

    int *output = malloc(size * sizeof(int));

    if (output == NULL)
    {
        return 1;
    }

    for (int i = size - 1; i >= 0; i--) 
    {
        output[counts_cumulative[nums[i]] - 1] = nums[i];
        
        counts_cumulative[nums[i]]--;
    }

    for (int i = 0; i < size; i++) 
    {
        nums[i] = output[i];
    }


    for (int i = 0; i < size; i++)
    {
        printf("%i ", nums[i]);
    }

    free(output);

    free(nums);
}

int count_occurences(int arr[], int size, int n)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == n)
        {
            count++;
        }
    }

    return count;
}
