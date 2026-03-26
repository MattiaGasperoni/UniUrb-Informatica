#include <stdio.h>
int calcola_fatt(int);
int calcola_fatt_ric(int);
int calcola_fib(int);
int calcola_fib_ric(int);
int main()
{
    int n,
        esito_lettura,       
        acquisizione_errata;
    do
    {   
        printf("Digita un numero: ");
        esito_lettura = scanf("%d",
                              &n);
        acquisizione_errata = esito_lettura != 1;
        if (acquisizione_errata)
            printf("\nNumero non accettabile!\n");
        while (getchar() != '\n');
    }
    while (acquisizione_errata);

    printf("\nIl fattoriale di %d : %d\n", n, calcola_fatt(n));
    printf("Il fibonacci di %d : %d\n", n, calcola_fib(n));

    printf("\nIl fattoriale ric di %d : %d\n", n, calcola_fatt_ric(n));
    printf("Il fibonacci ric di %d : %d\n", n, calcola_fib_ric(n));
    return(0);
}

int calcola_fatt(int n)
{
 int fatt,
 i;

 for (fatt = 1, i = 2;(i <= n);i++)
    fatt *= i;
 return(fatt);
}

int calcola_fib(int n)
{
    int fib,
        ultimo,
        penultimo,
        i;

    if ((n == 1) || (n == 2))
        fib = 1;
    else
        for (ultimo = penultimo = 1, i = 3;
            (i <= n);
            i++)
        {
            fib = ultimo + penultimo;
            penultimo = ultimo;
            ultimo = fib;
        }
    return(fib);
}
int calcola_fatt_ric(int n)
{
    int fatt;

    if (n == 1)
        fatt = 1;
    else
        fatt = n * calcola_fatt_ric(n - 1);
    return(fatt);
}
int calcola_fib_ric(int n)
{
    int fib;

    if ((n == 1) || (n == 2))
        fib = 1;
    else
        fib = calcola_fib_ric(n - 1) + calcola_fib_ric(n - 2);
    return(fib);
}
