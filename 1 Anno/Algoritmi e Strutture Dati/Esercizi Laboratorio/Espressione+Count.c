#include <stdlib.h>
#include <stdio.h>


long int calcola_fatt(long int n, int *count);
long int calcola_fatt_ric(long int n, int *count);
long int calcola_fib(long int n, int *count);
long int calcola_fib_ric(long int n, int *count);

int main()
{
  int i, j, h, k, n, c1, c2, c3, c4, esito_lettura, acquisizione_errata;
   
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
  c1 = 0;c2 = 0;c3 = 0;c4 = 0;

  printf("Compute 1...\n");
  i = calcola_fatt(n, &c1);
  printf("... fatto!\n");

  printf("Compute 2...\n");
  j = calcola_fatt_ric(n, &c2);
  printf("... fatto!\n");

  printf("Compute 3...\n");
  h = calcola_fib(n, &c3);
  printf("... fatto!\n");

  printf("Compute 4...\n");
  k = calcola_fib_ric(n, &c4);
  printf("... fatto!\n");

  printf("\nfattoriale non ricorsivo   = %d, in %d steps\n",i,c1);
  printf("fattoriale ricorsivo       = %d, in %d steps\n",j,c2);
  printf("\nfibonacci non ricorsivo    = %d, in %d steps\n",h,c3);
  printf("fibonacci ricorsivo        = %d, in %d steps\n",k,c4);
  return(0);
  
}

long int calcola_fatt(long int n, int *count)
{
	long int fatt,i;
	(*count)++;
	for (fatt = 1, i = 2;(i <= n);i++) {
		fatt *= i;
		(*count)+=3;
	}
    (*count)++;
	return(fatt);
}

long int calcola_fatt_ric(long int n, int *count)
  {
    long int fatt;

    (*count)++;
    if (n == 1) {
      fatt = 1;
      (*count)++;
    }
    else {
	    /*(*count)++;*/
	    fatt = n * calcola_fatt_ric(n - 1, count);
        (*count)++;
    }
    return(fatt);
  }

long int calcola_fib(long int n, int *count)
{
    long int fib,
             ultimo,
             penultimo,
             i;

    (*count)++;
    if ((n == 1) || (n == 2))
        fib = 1;
    else
        for (ultimo = penultimo = 1, i = 3;
            (i <= n);
            i++)
        {
            (*count)++;
            fib = ultimo + penultimo;
            penultimo = ultimo;
            ultimo = fib;
        }
    (*count)++;
    return(fib);
}

long int calcola_fib_ric(long int n, int *count)
{
    long int fib;

    (*count)++;
    if ((n == 1) || (n == 2))
    {
        fib = 1;
        (*count)++;
    }
        
    else
    {
        fib = calcola_fib_ric((n - 1),count) + calcola_fib_ric((n - 2),count);
        (*count)++;
    }
        
    return(fib);
}

