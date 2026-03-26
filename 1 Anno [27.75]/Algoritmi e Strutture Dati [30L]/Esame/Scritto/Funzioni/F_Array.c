#include <stdlib.h>
#include <stdio.h>



/* dichiarazione funzioni*/
void stampa_array(double *a, int N);
void quicksort(double *a, int sx, int dx);


/* programma main */
int main (int argc, char **argv) {
    int N;
    double *a;
    
    a = (double *)malloc(sizeof(double)*N);

    quicksort(a,0,N-1);
    return(0);
}
                    
void stampa_array(double *a, int N)
{
    int i;
    
    for(i=0;i<N;i++)
        printf("%d. %lf\n",i+1,a[i]);
}

void quicksort(double *a, int sx, int dx)
{
    double pivot, tmp;
    int i, j;
    
    /* crea la tripartizione */
    for (pivot = a[(sx + dx) / 2], i = sx, j = dx; (i <= j);) {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j) {
            if (i < j) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            i++;
            j--;
        }
    }
    /* ordina la prima e la terza parte se contenenti piu‘ di un elemento */
    if (sx < j)
        quicksort(a,sx,j);
    if (i < dx)
        quicksort(a,i,dx);
}

