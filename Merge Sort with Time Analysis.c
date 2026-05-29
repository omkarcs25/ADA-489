#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000

int arr[MAX], temp[MAX];

void merge(int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid)
        temp[k++] = arr[i++];

    while(j <= high)
        temp[k++] = arr[j++];

    for(i = low; i <= high; i++)
        arr[i] = temp[i];
}

void mergeSort(int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main()
{
    int n, i;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    start = clock();

    mergeSort(0, n - 1);

    end = clock();

    printf("Sorted Array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nTime Taken = %f seconds\n", time_taken);

    return 0;
}
