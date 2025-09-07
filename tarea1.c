#include <stdio.h>
#include <string.h>  

int main() {
    int c1[] = {5, 6, 7, 8,7,3,11,0,1,2,3,4,9,9,7,2};
    int c2[] = {1,2,3,4,9,9,7,2,5,6,7,8,7,3,11,0};

    int n = sizeof(c1) / sizeof(c1[0]);
    int m = sizeof(c2) / sizeof(c2[0]);

    int resultado[n + m];
    memset(resultado, 0, sizeof(resultado));  

    int i, j, producto, posicion, acarreo, inicio;

    for(i = n-1; i >= 0; i--) {
        for(j = m-1; j >= 0; j--) {
            producto = c1[i] * c2[j];
            posicion = i + j + 1;
            resultado[posicion] += producto;
        }
    }

    for(i = n + m - 1; i > 0; i--) {
        if(resultado[i] >= 10) {
            acarreo = resultado[i] / 10;
            resultado[i] %= 10;
            resultado[i-1] += acarreo;
        }
    }

    inicio = (resultado[0] != 0) ? 0 : 1;

    printf("El resultado es: ");
    for(i = inicio; i < n + m; i++) {
        printf("%d", resultado[i]);
    }
    printf("\n");

    return 0;
}
