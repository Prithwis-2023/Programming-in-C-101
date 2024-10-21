#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int size, int i);

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

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(nums, size, i);
    }

    for (int i = size - 1; i >= 0; i--)
    {
        int temp = nums[0];
        
        nums[0] = nums[i];
        
        nums[i] = temp;

        heapify(nums, i, 0);
    }
    
    for (int i = 0; i < size; i++) {printf("%i ", nums[i]);};
    
    free(nums);

    return 0;
}

void heapify(int arr[], int size, int i)
{
    int largest = i;

    int left_child = 2 * i + 1;

    int right_child = 2 * i + 2;

    if (left_child < size && arr[left_child] > largest)
    {
        largest = left_child;
    }

    if (right_child < size && arr[right_child] > largest)
    {
        largest = right_child;
    }

    if (largest != i)
    {
        int temp = arr[i];

        arr[i] = arr[largest];

        arr[largest] = temp;

        heapify(arr, size, largest);
    }
}