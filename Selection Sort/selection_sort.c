#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int len);
void swap(int arr[], int f_index, int s_index);
void selection_sort(int arr[], int len);

int main()
{
    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4};
    int len = sizeof(arr) / sizeof(int);

    printf("\nThe array before sorting:\n");
    print_array(arr, len);

    selection_sort(arr, len);

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

void swap(int arr[], int f_index, int s_index)
{
    int temp = arr[f_index];
    arr[f_index] = arr[s_index];
    arr[s_index] = temp;
}

void selection_sort(int arr[], int len)
{
    int min_index;
    for (int i = 0; i < len - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (i != min_index)
        {
            swap(arr, i, min_index);
        }
    }
}
