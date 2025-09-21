#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int busqueda_binaria(int lista[], int n, int objetivo) {
    int izquierda = 0;
    int derecha = n - 1;

    while (izquierda <= derecha) {
        int medio = (izquierda + derecha) / 2;

        if (lista[medio] == objetivo) {
            return medio;
        } else if (lista[medio] < objetivo) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }
    return -1;
}

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int tamanos[] = {1000, 10000, 100000};
    int num_tamanos = sizeof(tamanos) / sizeof(tamanos[0]);

    printf("%-10s %-15s %-15s %-12s\n", "Tamaño", "Tiempo (s)", "Memoria (MB)", "Encontrado");

    srand(time(NULL)); 
    for (int t = 0; t < num_tamanos; t++) {
        int n = tamanos[t];

        int *lista = (int*) malloc(n * sizeof(int));
        if (lista == NULL) {
            printf("Error al asignar memoria\n");
            return 1;
        }

        for (int i = 0; i < n; i++) {
            lista[i] = rand() % n;
        }

        qsort(lista, n, sizeof(int), comparar);

        int objetivo = lista[rand() % n];

        clock_t inicio = clock();
        int indice = busqueda_binaria(lista, n, objetivo);
        clock_t fin = clock();

        double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

        double memoria_MB = (n * sizeof(int)) / (1024.0 * 1024.0);

        printf("%-10d %-15f %-15f %-12s\n",
               n, tiempo, memoria_MB, (indice != -1 ? "Sí" : "No"));

        free(lista); 
    }

    return 0;
}
