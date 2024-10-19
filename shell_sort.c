#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void ShellSort(int arr[], int n);

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

    ShellSort(nums, size);

    for (int i = 0; i < size; i++) {printf("%i ", nums[i]);};

    free(nums);

}

void ShellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];

            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}