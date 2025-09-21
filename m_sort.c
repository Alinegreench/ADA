#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int izquierda[], int nIzq, int derecha[], int nDer) {
    int i = 0, j = 0, k = 0;

    while (i < nIzq && j < nDer) {
        if (izquierda[i] <= derecha[j]) {
            arr[k++] = izquierda[i++];
        } else {
            arr[k++] = derecha[j++];
        }
    }

    while (i < nIzq) {
        arr[k++] = izquierda[i++];
    }
    while (j < nDer) {
        arr[k++] = derecha[j++];
    }
}

void merge_sort(int arr[], int n) {
    if (n <= 1) return;

    int mitad = n / 2;
    int *izquierda = (int*)malloc(mitad * sizeof(int));
    int *derecha = (int*)malloc((n - mitad) * sizeof(int));

    for (int i = 0; i < mitad; i++) izquierda[i] = arr[i];
    for (int i = mitad; i < n; i++) derecha[i - mitad] = arr[i];

    merge_sort(izquierda, mitad);
    merge_sort(derecha, n - mitad);

    merge(arr, izquierda, mitad, derecha, n - mitad);

    free(izquierda);
    free(derecha);
}

int main() {
    int tamanos[] = {1000, 10000, 100000};
    int nPruebas = 3;

    printf("%-10s %-15s %-15s\n", "Tamaño", "Tiempo (s)", "Memoria (KB)");

    for (int i = 0; i < nPruebas; i++) {
        int n = tamanos[i];
        int *lista = (int*)malloc(n * sizeof(int));

        for (int j = 0; j < n; j++) {
            lista[j] = rand() % n;
        }

        clock_t start = clock();
        merge_sort(lista, n);
        clock_t end = clock();

        double tiempo = (double)(end - start) / CLOCKS_PER_SEC;
        size_t memoria = n * sizeof(int) / 1024; 

        printf("%-10d %-15f %-15zu\n", n, tiempo, memoria);

        free(lista);
    }

    return 0;
}
