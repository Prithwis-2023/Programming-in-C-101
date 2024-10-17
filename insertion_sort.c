#include <stdio.h>
#include <stdlib.h>

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

    for (int i = 1; i < size; i++)
    {
        int tmp = nums[i];

        int j;

        for (j = i - 1; j >= 0 && nums[j] > tmp; j--)
        {
            nums[j + 1] = nums[j];
        }

        nums[j + 1] = tmp;

    }

    for (int i = 0; i < size; i++)
    {
        printf("%i ", nums[i]);
    }

    printf("\n");
}