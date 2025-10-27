#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Intercambia dos elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partición de QuickSort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

// QuickSelect recursivo (Divide y vencerás)
int quickselect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);
        if (pi == k)
            return arr[pi];
        else if (pi > k)
            return quickselect(arr, low, pi - 1, k);
        else
            return quickselect(arr, pi + 1, high, k);
    }
    return -1;
}

int main() {
    int sizes[] = {100, 1000, 100000};
    int n_sizes = 3;

    srand(time(NULL));

    for (int s = 0; s < n_sizes; s++) {
        int n = sizes[s];
        int *arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            arr[i] = rand() % 1000000;
        int k = rand() % n;

        clock_t start = clock();
        int kth = quickselect(arr, 0, n - 1, k);
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("n=%6d | k=%6d | Elemento=%d | Tiempo=%.6f s\n", n, k, kth, time_taken);

        free(arr);
    }

    return 0;
}

