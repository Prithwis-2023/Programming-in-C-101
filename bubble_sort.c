#include <stdio.h>
#include <ctype.h>
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

    for (int i = 0; i <= size - 1; i++) 
    {
        for (int j = 0; j <= size - 2; j++) 
        {
            if (nums[j] > nums[j + 1]) 
            {
                int temp = nums[j];

                nums[j] = nums[j + 1];

                nums[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%i ", *(nums + i));
    }

    free(nums);

    return 0;
}