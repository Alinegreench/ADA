#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fusión modificada para contar inversiones
long long merge_count(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left;
    long long inv_count = 0;

    while (i <= mid - 1 && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inv_count += (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

// Merge sort modificado
long long merge_sort_count(int arr[], int temp[], int left, int right) {
    long long inv_count = 0;
    if (right > left) {
        int mid = (right + left) / 2;
        inv_count += merge_sort_count(arr, temp, left, mid);
        inv_count += merge_sort_count(arr, temp, mid + 1, right);
        inv_count += merge_count(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int main() {
    int sizes[] = {100, 1000, 100000};
    int n_sizes = 3;

    srand(time(NULL));

    for (int s = 0; s < n_sizes; s++) {
        int n = sizes[s];
        int *arr = (int*)malloc(n * sizeof(int));
        int *temp = (int*)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            arr[i] = rand() % 1000000;

        clock_t start = clock();
        long long inv_count = merge_sort_count(arr, temp, 0, n - 1);
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("n=%6d | Inversiones=%lld | Tiempo=%.6f s\n", n, inv_count, time_taken);

        free(arr);
        free(temp);
    }

    return 0;
}
