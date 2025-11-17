#include <stdio.h>

// Estructura para guardar cada objeto con su peso, valor y ratio
typedef struct {
    float ratio;   // valor/peso (beneficio por unidad de peso)
    int peso;
    int valor;
} Objeto;

// Función para ordenar los objetos por ratio descendente (mayor a menor)
void ordenar_por_ratio(Objeto objetos[], int n) {
    int i, j;
    Objeto temp;

    // Ordenamiento burbuja (simple y claro para principiantes)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {

            // Si el objeto de adelante tiene mayor ratio, se intercambian
            if (objetos[j].ratio < objetos[j + 1].ratio) {
                temp = objetos[j];
                objetos[j] = objetos[j + 1];
                objetos[j + 1] = temp;
            }
        }
    }
}

float mochila_fraccionaria(int pesos[], int valores[], int n, int capacidad) {
    Objeto objetos[n];
    int i;

    // Crear lista de objetos con ratio
    for (i = 0; i < n; i++) {
        objetos[i].peso = pesos[i];
        objetos[i].valor = valores[i];
        objetos[i].ratio = (float)valores[i] / pesos[i];
    }

    // Ordenar por ratio (valor/peso) de mayor a menor
    ordenar_por_ratio(objetos, n);

    float ganancia_total = 0.0;
    int capacidad_restante = capacidad;

    // Proceso voraz
    for (i = 0; i < n; i++) {

        // Si ya no queda espacio, termina
        if (capacidad_restante == 0)
            break;

        if (objetos[i].peso <= capacidad_restante) {
            // Tomamos el objeto COMPLETO
            printf("Tomamos COMPLETO el objeto (valor=%d, peso=%d)\n",
                   objetos[i].valor, objetos[i].peso);

            ganancia_total += objetos[i].valor;
            capacidad_restante -= objetos[i].peso;

        } else {
            // Tomamos SOLO una fracción
            float fraccion = (float)capacidad_restante / objetos[i].peso;

            printf("Tomamos %.2f del objeto (valor=%d, peso=%d)\n",
                   fraccion, objetos[i].valor, objetos[i].peso);

            ganancia_total += objetos[i].valor * fraccion;
            capacidad_restante = 0;
        }
    }

    printf("\nGanancia total obtenida: %.2f\n", ganancia_total);
    return ganancia_total;
}

int main() {
    int pesos[] = {10, 20, 30};
    int valores[] = {60, 100, 120};
    int capacidad = 50;
    int n = 3;

    mochila_fraccionaria(pesos, valores, n, capacidad);

    return 0;
}
