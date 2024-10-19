#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void MergeSort(int arr[], int left, int right);

void Merge(int arr[], int left, int mid, int right);

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

    MergeSort(nums, 0, size - 1);

    for (int i = 0; i < size; i++) {printf("%i ", nums[i]);};

    free(nums);

    return 0;
}

void MergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        MergeSort(arr, left, mid);

        MergeSort(arr, mid + 1, right);

        Merge(arr, left, mid, right);
    }
}

void Merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;

    int n2 = right - mid;

    int *L = malloc(n1 * sizeof(int));

    int *R = malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL)
    {
        return;
    }

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];

            i++;
        }
        else
        {
            arr[k] = R[j];

            j++;
        }

        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];

        i++;

        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];

        j++;

        k++;
    }

    free(L);

    free(R);    
}