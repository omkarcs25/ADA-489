#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (1)
    {
        while (i <= high && a[i] <= pivot)
            i++;

        while (a[j] > pivot)
            j--;

        if (i < j)
            swap(&a[i], &a[j]);
        else
            break;
    }

    swap(&a[low], &a[j]);
    return j;
}

void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int pos = partition(a, low, high);

        quicksort(a, low, pos - 1);
        quicksort(a, pos + 1, high);
    }
}

int main()
{
    int n, i;
    clock_t start, end;
    double time_taken;

    printf("N\tTime Taken (seconds)\n");

    for (n = 10000; n <= 50000; n += 10000)
    {
        int *a = (int *)malloc(n * sizeof(int));

        for (i = 0; i < n; i++)
            a[i] = rand();

        start = clock();

        quicksort(a, 0, n - 1);

        end = clock();

        time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d\t%f\n", n, time_taken);

        free(a);
    }

    return 0;
}
