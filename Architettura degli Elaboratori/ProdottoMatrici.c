#include <stdio.h>

int main() 
{
	/* dichiarazione delle variabili locali alla funzione*/
	
    double a[2][2] = 
					{{4.3, 2.1}, 
					{3.3, 5.2}};	/*input: Matrice A*/

    double b[2][2] = 
					{{2.3, 1.1}, 
					{4.3, 6.2}};	/*input: Matrice B*/

    int i, j, k,  					/* lavoro: variabili per lo scorrimento delle matrici*/
        n = 2; 						/* lavoro: dimensione delle matrici*/
		
    double c[2][2] = 
					{{0.0, 0.0}, 
					{0.0, 0.0}};	/*output: Matrice C risultato*/ 

    /*calcolo del prodotto delle matrici A e B*/ 
    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++) 
            for (k = 0; k < n; k++) 
                c[i][j] += a[i][k] * b[k][j];

    /*stampa del prodotto delle matrici*/
    printf("Matrice Prodotto:\n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
            printf("%.2f ", c[i][j]);
        printf("\n");
    }

    return 0;
}


