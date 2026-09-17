/*
Mattia Gasperoni
Numero di matricola : 329235
*/
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int N;
    double dato; /*il tipo va in base al problema richiesto*/

    srand(1);/* Inizializzazione generatore numeri pseudocasuali*/

    /*Genera casualmente N numeri REALI compresi tra 0 e 1 (compresi gli estremi)*/
    dato = (double)rand()/RAND_MAX;

    /*Genera casualmente N numeri REALI compresi tra 10 e 50 (compresi gli estremi)*/
    dato = 10 + 40*(double)rand()/RAND_MAX;

    /*Genera casualmente N numeri INTERI x tali che 0 ≤ x ≤ 100 */
    dato = rand() % ((100) + 1);

    /*Genera casualmente N numeri INTERI compresi tra 0 e 10 · N (compresi gli estremi)*/
    dato = rand() % ((10 * N) +1);

    /*Genera casualmente N numeri INTERI compresi tra 0 e 3 · N (compresi gli estremi)*/
    dato = rand() % ((3 * N) + 1);
}