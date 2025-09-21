#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenamiento_burbuja(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int tamanos[] = {1000, 10000};
    int num_tamanos = sizeof(tamanos) / sizeof(tamanos[0]);

    printf("%-10s %-15s %-15s %-12s\n", "Tamaño", "Tiempo (s)", "Memoria (MB)", "Ordenado");

    for (int k = 0; k < num_tamanos; k++) {
        int n = tamanos[k];

        int *arr = (int*)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Error al reservar memoria\n");
            return 1;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = rand() % n;
        }

        clock_t start = clock();
        ordenamiento_burbuja(arr, n);
        clock_t end = clock();

        double tiempo = (double)(end - start) / CLOCKS_PER_SEC;

        double memoriaMB = (double)(n * sizeof(int)) / (1024.0 * 1024.0);

        printf("%-10d %-15f %-15f %-12s\n", n, tiempo, memoriaMB, "Sí");

        free(arr); 
    }

    return 0;
}
