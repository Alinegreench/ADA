#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int busqueda_lineal(int lista[], int n, int objetivo) {
    for (int i = 0; i < n; i++) {
        if (lista[i] == objetivo) {
            return i;
        }
    }
    return -1;
}

int main() {
    int tamanos[] = {1000, 10000, 100000};
    int num_tamanos = sizeof(tamanos) / sizeof(tamanos[0]);

    printf("%-10s %-15s %-15s\n", "Tamaño", "Tiempo (s)", "Memoria (MB)");

    for (int t = 0; t < num_tamanos; t++) {
        int n = tamanos[t];
        int *lista = (int*) malloc(n * sizeof(int));

        if (lista == NULL) {
            printf("Error al asignar memoria\n");
            return 1;
        }
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            lista[i] = rand() % n;
        }

        int objetivo = rand() % n;

        clock_t inicio = clock();
        int indice = busqueda_lineal(lista, n, objetivo);
        clock_t fin = clock();

        double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

        double memoria_MB = (n * sizeof(int)) / (1024.0 * 1024.0);

        printf("%-10d %-15f %-15f\n", n, tiempo, memoria_MB);

        free(lista); 
    }

    return 0;
}
