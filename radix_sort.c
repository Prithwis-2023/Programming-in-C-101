#include <stdio.h>
#include <stdlib.h>

int count_occurences (int arr[], int size, int n);

int* counting_sort(int arr[], int size);

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    int size = atoi(argv[1]);

    int *nums = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {scanf("%i", &nums[i]);};


}

//co-routine for counting sort (stable algorithm)

int* counting_sort(int arr[], int size, int exp)
{
    int max = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int *counts = malloc((max + 1) * sizeof(int));

    int *counts_cumulative = malloc((max + 1) * sizeof(int));

    int *output = malloc(size * sizeof(int));

    if (counts == NULL || counts_cumulative == NULL || output == NULL)
    {
        return 1;
    }

    for (int i = 0; i < max + 1; i++)
    {
        counts[i] = count_occurences(arr, size, i);
    }

    for (int i = 1; i < max + 1; i++)
    {
        counts_cumulative[i] = i + counts_cumulative[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        output[counts_cumulative[arr[i]] - 1] = arr[i];

        counts_cumulative[arr[i]]--;
    }

    for (int i = 0; i < size; i++) 
    {
        arr[i] = output[i];
    }

    return arr;
}

int count_occurences (int arr[], int size, int n)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if(arr[i] == n)
        {
            count++;
        }
    }

    return count;
}