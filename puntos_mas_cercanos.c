#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    double x, y;
} Punto;

// Calcula la distancia euclidiana
double distancia(Punto a, Punto b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

// Ordena por coordenada X
int cmpX(const void* a, const void* b) {
    Punto *p1 = (Punto*)a, *p2 = (Punto*)b;
    return (p1->x > p2->x) - (p1->x < p2->x);
}

// Ordena por coordenada Y
int cmpY(const void* a, const void* b) {
    Punto *p1 = (Punto*)a, *p2 = (Punto*)b;
    return (p1->y > p2->y) - (p1->y < p2->y);
}

// Calcula distancia mínima directamente (brute force)
double min_dist_brute(Punto pts[], int n) {
    double min = INFINITY;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (distancia(pts[i], pts[j]) < min)
                min = distancia(pts[i], pts[j]);
    return min;
}

// Divide y vencerás
double closest_pair(Punto pts[], int n) {
    if (n <= 3) return min_dist_brute(pts, n);

    int mid = n / 2;
    Punto midPoint = pts[mid];

    double dl = closest_pair(pts, mid);
    double dr = closest_pair(pts + mid, n - mid);
    double d = (dl < dr) ? dl : dr;

    Punto *strip = (Punto*)malloc(n * sizeof(Punto));
    int j = 0;
    for (int i = 0; i < n; i++)
        if (fabs(pts[i].x - midPoint.x) < d)
            strip[j++] = pts[i];

    qsort(strip, j, sizeof(Punto), cmpY);

    for (int i = 0; i < j; ++i)
        for (int k = i + 1; k < j && (strip[k].y - strip[i].y) < d; ++k)
            if (distancia(strip[i], strip[k]) < d)
                d = distancia(strip[i], strip[k]);

    free(strip);
    return d;
}

int main() {
    int sizes[] = {10, 100, 1000, 100000};
    int n_sizes = 4;

    srand(time(NULL));

    for (int s = 0; s < n_sizes; s++) {
        int n = sizes[s];
        Punto *pts = (Punto*)malloc(n * sizeof(Punto));

        for (int i = 0; i < n; i++) {
            pts[i].x = ((double)rand() / RAND_MAX) * 1000.0;
            pts[i].y = ((double)rand() / RAND_MAX) * 1000.0;
        }

        qsort(pts, n, sizeof(Punto), cmpX);

        clock_t start = clock();
        double min_dist = closest_pair(pts, n);
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("n=%6d | Distancia mínima=%.6f | Tiempo=%.6f s\n", n, min_dist, time_taken);

        free(pts);
    }

    return 0;
}
