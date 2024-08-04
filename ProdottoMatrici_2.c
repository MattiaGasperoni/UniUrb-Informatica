#include <stdio.h>

int main() 
{
    int i, j, k;
    int n = 2; // Dimensione delle matrici

    /*Matrice A (2x2)*/ 
    double a[2][2] = {{4.3, 2.1}, {3.3, 5.2}};

    /*Matrice B (2x2)*/ 
    double b[2][2] = {{2.3, 1.1}, {4.3, 6.2}};

    /*Matrice C risultato*/ 
    double c[2][2] = {{0.0, 0.0}, {0.0, 0.0}};

    /*Calcolo del prodotto delle matrici*/ 
    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++) 
            for (k = 0; k < n; k++) 
                c[i][j] += a[i][k] * b[k][j];

    /*Stampa la matrice Prodotto C*/
    printf("Matrice Prodotto:\n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
            printf("%.2f ", c[i][j]);
        printf("\n");
    }

    return 0;
}
