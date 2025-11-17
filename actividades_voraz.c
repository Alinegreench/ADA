#include <stdio.h>

void seleccionar_actividades(int actividades[][2], int n) {
    // 1. Ordenamiento manual por tiempo de fin (burbuja simple)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (actividades[j][1] < actividades[i][1]) {
                // Intercambiar filas completas: inicio y fin
                int temp0 = actividades[i][0];
                int temp1 = actividades[i][1];

                actividades[i][0] = actividades[j][0];
                actividades[i][1] = actividades[j][1];

                actividades[j][0] = temp0;
                actividades[j][1] = temp1;
            }
        }
    }

    // 2. Selección de actividades compatibles
    int fin_anterior = -1;

    printf("Actividades seleccionadas:\n");
    for (int i = 0; i < n; i++) {
        int inicio = actividades[i][0];
        int fin    = actividades[i][1];

        if (inicio >= fin_anterior) {
            printf("[%d, %d]\n", inicio, fin);
            fin_anterior = fin;
        }
    }
}

int main() {
    int actividades[][2] = {
        {1,4}, {3,5}, {0,6}, {5,7}, {3,9}, {5,9},
        {6,10}, {8,11}, {8,12}, {2,14}, {12,16}
    };

    int n = sizeof(actividades) / sizeof(actividades[0]);

    seleccionar_actividades(actividades, n);

    return 0;
}
