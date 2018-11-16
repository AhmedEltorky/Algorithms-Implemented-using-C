#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int len);
void swap(int arr[], int f_index, int s_index);
int partition(int arr[], int str_indx, int end_indx);
void quick_sort(int arr[], int str_indx, int end_indx);

int main()
{
    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4};
    int len = sizeof(arr) / sizeof(int);

    printf("\nThe array before sorting:\n");
    print_array(arr, len);

    quick_sort(arr, 0, len - 1);

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

int partition(int arr[], int str_indx, int end_indx)
{
    int pivot = arr[end_indx];
    int p_index = str_indx;
    for (int i = str_indx; i < end_indx; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr, i, p_index);
            p_index++;
        }
    }
    swap(arr, end_indx, p_index);
    return p_index;
}

void quick_sort(int arr[], int str_indx, int end_indx)
{
    if (str_indx >= end_indx)
    {
        return;
    }
    int p_index = partition(arr, str_indx, end_indx);
    quick_sort(arr, str_indx, p_index - 1);
    quick_sort(arr, p_index + 1, end_indx);
}
