#include <stdio.h>

int main (void)
{
     int arr[] = {12, 31, 25, 8, 32, 17}, num, flag = 0;

     int size = sizeof(arr) / sizeof(int);

     scanf("%i", &num);

     for (int i = 0; i < size; i++)
     {
        if (num == arr[i])
        {
            printf("Found!\n");

            break;
        }

        else
        {
            flag++;

            continue;
        }
     }

     if (flag == size)
     {
        printf("Not Found!\n");
     }
}