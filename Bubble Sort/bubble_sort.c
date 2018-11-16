#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y);
void print_array(int arr[], int arr_len);
void bubble_sort(int arr[], int arr_len);

int main()
{
    int arr[] = {2, 7, 4, 1, 5, 3};
    int len = sizeof(arr) / sizeof(int);

    printf("\nThe array before sorting:\n");
    print_array(arr, len);

    bubble_sort(arr, len);

    printf("\nThe array before sorting:\n");
    print_array(arr, len);

    return 0;
}

void print_array(int arr[], int arr_len)
{
    for (int i = 0; i < arr_len; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int arr[], int arr_len)
{
    int swap_flag;
    for (int i = arr_len - 1; i > 0; i--)
    {
        swap_flag = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swap_flag = 1;
            }
        }
        if (swap_flag == 0)
        {
            break;
        }
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}