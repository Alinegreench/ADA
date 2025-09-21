#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* fibonacci_hasta_valor(int limite, int *out_len) {
    if (limite < 0) {
        *out_len = 0;
        return NULL;
    }

    int capacidad = 16;
    int *serie = (int*)malloc(capacidad * sizeof(int));
    int n = 0;
    serie[n++] = 0;
    if (limite == 0) {
        *out_len = n;
        return serie;
    }
    serie[n++] = 1;

    while (1) {
        int siguiente = serie[n-1] + serie[n-2];
        if (siguiente > limite) break;
        if (n >= capacidad) {
            capacidad *= 2;
            int *tmp = (int*)realloc(serie, capacidad * sizeof(int));
            if (!tmp) {
                free(serie);
                *out_len = 0;
                return NULL;
            }
            serie = tmp;
        }
        serie[n++] = siguiente;
    }

    *out_len = n;
    return serie;
}

int main(void) {
    int limite = 20;
    int len = 0;

    clock_t start = clock();
    int *serie = fibonacci_hasta_valor(limite, &len);
    clock_t end = clock();

    double tiempo = (double)(end - start) / CLOCKS_PER_SEC;
    size_t memoria = len * sizeof(int) / 1024; // memoria aproximada en KB

    printf("Serie de Fibonacci (último <= %d): ", limite);
    for (int i = 0; i < len; i++) {
        if (i) printf(" ");
        printf("%d", serie[i]);
    }
    printf("\n");

    printf("Tiempo: %f s, Memoria aproximada: %zu KB\n", tiempo, memoria);

    free(serie);
    return 0;
}

