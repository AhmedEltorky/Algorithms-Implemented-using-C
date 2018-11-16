#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int len);
void merge_sort(int arr[], int n);
void merge(int left_arr[], int nl, int right_arr[], int nr, int arr[], int n);

int main()
{
    int arr[] = {2, 4, 1, 6, 8, 5, 3, 7};
    int len = sizeof(arr) / sizeof(int);

    printf("\nThe array before sorting:\n");
    print_array(arr, len);

    merge_sort(arr, len);

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

void merge_sort(int arr[], int n)
{
    if (n < 2)
    {
        return;
    }
    int mid = n / 2;
    int left_arr[mid], right_arr[n - mid];
    for (int i = 0; i < mid; i++)
    {
        left_arr[i] = arr[i];
    }
    for (int i = 0; i < n - mid; i++)
    {
        right_arr[i] = arr[mid + i];
    }
    merge_sort(left_arr, mid);
    merge_sort(right_arr, n - mid);
    merge(left_arr, mid, right_arr, n - mid, arr, n);
}

void merge(int left_arr[], int nl, int right_arr[], int nr, int arr[], int n)
{
    int i = 0, j = 0;
    for (int k = 0; k < n; k++)
    {
        if (i < nl && j < nr)
        {
            if (left_arr[i] <= right_arr[j])
            {
                arr[k] = left_arr[i];
                i++;
            }
            else
            {
                arr[k] = right_arr[j];
                j++;
            }
        }
        else
        {
            if (i < nl)
            {
                arr[k] = left_arr[i];
                i++;
            }
            else if (j < nr)
            {
                arr[k] = right_arr[j];
                j++;
            }
        }
    }
}
