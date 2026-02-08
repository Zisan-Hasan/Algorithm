#include <stdio.h>


void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}


void mergesort(int arr[], int n)
{
    for (int size = 1; size <= n - 1; size = 2 * size)
    {
        for (int start = 0; start < n - 1; start += 2 * size)
        {
            int mid = start + size - 1;
            int end = (start + 2 * size - 1 < n - 1)
                        ? start + 2 * size - 1
                        : n - 1;

            if (mid < end)
                merge(arr, start, mid, end);
        }
    }
}


int main()
{
    FILE *fp;
    int n;

    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("Error: Cannot open file\n");
        return 1;
    }

    fscanf(fp, "%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
        fscanf(fp, "%d", &arr[i]);

    fclose(fp);

    mergesort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

