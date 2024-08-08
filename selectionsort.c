#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

int main() {
    while (1) {
        int arr[10000], n, i;
        printf("Enter the number of elements in an array: ");
        scanf("%d", &n);
        printf("All the elements: ");
        srand(time(0));
        for (i = 0; i < n; i++) {
            arr[i] = rand();
            printf("%d ", arr[i]);
        }
        clock_t start, end;
        double cpu_time_used;
        start = clock();
        selection_sort(arr, n);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("\nAfter sorting\n");
        for (i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\nTime taken to sort %d elements: %f seconds\n", n, cpu_time_used);
    }
    return 0;
}
