#include <stdio.h>

int binarySearch(int arr[], int left, int right, int num);

int main (void)
{
    int arr[] = {3, 4, 5, 6, 7, 8, 9}, num;

    scanf("%i", &num);

    int size = sizeof(arr) / sizeof(int);

    printf("%i\n", binarySearch(arr, 0, size - 1, num));
}

int binarySearch(int arr[], int left, int right, int num)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == num)
        {
            return mid;
        }

        else if (num < arr[mid])
        {
            return binarySearch(arr, left, mid - 1, num);
        }

        else if (num > arr[mid])
        {
            return binarySearch(arr, mid + 1, right, num);
        }

        else
        {
            return -1;
        }
    }
}