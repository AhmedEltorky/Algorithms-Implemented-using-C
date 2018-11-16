#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int len);
void insertion_sort(int arr[], int len);

int main()
{
    int arr[] = {2, 4, 1, 6, 8, 5, 3, 7};
    int len = sizeof(arr) / sizeof(int);

    printf("\nThe array before sorting:\n");
    print_array(arr, len);

    insertion_sort(arr, len);

    printf("\nThe array after sorting:\n");
    print_array(arr, len);

    return 0;
}

void print_array(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int value = arr[i];
        int hole = i;
        while (hole > 0 && arr[hole - 1] > value)
        {
            arr[hole] = arr[hole - 1];
            hole--;
        }
        arr[hole] = value;
    }
}
