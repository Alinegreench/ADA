#include <stdio.h>

void cambio_voraz(int N) {
    // Arreglo con las monedas disponibles
    int monedas[] = {25, 10, 5, 1};
    int cantidad;
    int i;

    printf("N = %d -> ", N);

    // Recorremos cada tipo de moneda
    for (i = 0; i < 4; i++) {
        int m = monedas[i];

        // Calculamos cuántas monedas de este tipo caben
        cantidad = N / m;

        // Si al menos cabe una, la mostramos
        if (cantidad > 0) {
            printf("%d:%d ", m, cantidad);
        }

        // Reducimos N al residuo
        N = N % m;
    }

    printf("\n");
}

int main() {
    // Probamos con varios valores de N
    int pruebas[] = {34, 87, 99, 123};
    int i;

    for (i = 0; i < 4; i++) {
        cambio_voraz(pruebas[i]);
    }

    return 0;
}
