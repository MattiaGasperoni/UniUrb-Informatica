#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int  validazione(void);
void random_array(int *, int);

void insertsort(int *,int);
void selectsort(int *,int);
void bubblesort(int *,int);
void mergesort(int *,int,int);
void fondi(int *, int, int, int);
void quicksort(int *, int , int);
void heapsort(int *,int);
void setaccia_heap(int *,int ,int );

void stampa_array(int*,int);

int main()
{
    int n;
    n = validazione();
    
    /*Start tempo*/
    clock_t t1,t2;
    double cpu_time;
    t1 = clock();
    
    /*Allocazione di Memoria*/
    int *a = (int *)malloc(n * sizeof(int));

    if (a == NULL)
    {
        printf("Errore nell'allocazione di memoria.\n");
        return 1;
    }
    /*Popolamento e Stampa random Array*/
    random_array(a,n);

    /*Ordinamento Array*/

    insertsort(a,n);
    /*selectsort(a,n);*/
    /*bubblesort(a,n);*/
    /*mergesort(a,a[0],a[-1]);*/
    /*quicksort(a,a[0],a[-1]);*/
    /*heapsort(a,n);*/

    /*Stampa Array ordinato*/
    stampa_array(a,n);
    
    /*fine tempo*/
    t2 = clock();
    cpu_time = ((double) (t2 - t1)) / CLOCKS_PER_SEC;

    printf("\nTempo per l'esecuzione del programma = %f secondi \n",cpu_time);
    return(0);
}

int validazione(void)
{
    
    int n,                
        esito_lettura,       /* lavoro: esito della scanf */
        acquisizione_errata; /* lavoro: esito complessivo dell’acquisizione */
    
    /*acquisizione e validazione stretta di un anno */
    do
    {   
        printf("Quanti elementi ha l'array?: ");
        esito_lettura = scanf("%d",
                              &n);
        acquisizione_errata = esito_lettura != 1;
        if (acquisizione_errata)
            printf("\nNumero non accettabile!\n");
        while (getchar() != '\n');
    }
    while (acquisizione_errata);
    return(n);
}

void random_array(int a[],int n)
{   
    int i;
    
    srand(time(NULL)); 
    /*Generatore di numeri casuali tra 1 e n*/
    for(i = 0; i < n ; i++)
    {
        a[i] = 1 + rand() % n; 
	    printf("%d\n", a[i]);
    }
}

void insertsort(int a[],int n)
{
    int valore_ins,i,j;

    for (i = 1;(i < n);i++)
    {
        for (valore_ins = a[i], j = i - 1;((j >= 0) && (a[j] > valore_ins));j--)
            a[j + 1] = a[j];
         if (j + 1 != i)
             a[j + 1] = valore_ins;
    }
}

void selectsort(int a[],int n)
{
    int valore_min, indice_valore_min, i, j;

    for (i = 0;(i < n - 1);i++)
    {
        for (valore_min = a[i], indice_valore_min = i, j = i + 1;(j < n);j++)
            if (a[j] < valore_min)
            {
                valore_min = a[j];
                indice_valore_min = j;
            }
        if (indice_valore_min != i)
        {
            a[indice_valore_min] = a[i];
            a[i] = valore_min;
        }
    }
}

void bubblesort(int a[],int n)
{
int tmp, i, j;

for (i = 1;(i < n);i++)
    for (j = n - 1;(j >= i);j--)
        if (a[j] < a[j - 1])
        {
            tmp = a[j - 1];
            a[j - 1] = a[j];
            a[j] = tmp;
        }
}

void mergesort(int a[], int sx, int dx)
{
    int mx;

    if (sx < dx)
    {
        mx = (sx + dx) / 2;
        mergesort(a,sx,mx);
        mergesort(a,mx + 1,dx);
        fondi(a,sx,mx,dx);
    }
}

void fondi(int a[], int sx, int mx, int dx)
{
    int *b, /* array di appoggio */
        i, /* indice per la parte sinistra di a (da sx ad m) */
        j, /* indice per la parte destra di a (da m + 1 a dx) */
        k; /* indice per la porzione di b da sx a dx */

    /* fondi ordinatamente le due parti finche’ sono entrambe non vuote */
    b = (int *)calloc(dx + 1,sizeof(int));
    for (i = sx, j = mx + 1, k = 0;((i <= mx) && (j <= dx));k++)
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
    while (i<=mx) 
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j<=dx) 
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (k=sx; k<=dx; k++)
        a[k] = b[k-sx];
    free(b);
}

void quicksort(int a[], int sx, int dx)
{
    int pivot, tmp, i, j;

    /* crea la tripartizione */
    for (pivot = a[(sx + dx) / 2], i = sx, j = dx; (i <= j);)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j)
        {
            if (i < j)
            {
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

void heapsort(int a[], /* a[0] non viene usato */int n)
{
    int tmp,sx,dx;

    /* prima fase: trasformare l’array in uno heap */
    for (sx = n / 2;(sx >= 1);sx--)
        setaccia_heap(a,sx,n);
    /* seconda fase: ordinare l’array mantenendo l’organizzazione ad heap */
    for (dx = n;(dx > 1);dx--)
    {
        tmp = a[1];
        a[1] = a[dx];
        a[dx] = tmp;
        setaccia_heap(a,1,dx - 1);
    }
}

void setaccia_heap(int a[],int sx,int dx)
{
    int nuovo_valore, i, j;

    for (nuovo_valore = a[sx], i = sx, j = 2 * i;(j <= dx);)
    {
        if ((j < dx) && (a[j + 1] > a[j]))
            j++;
        if (nuovo_valore < a[j])
        {
            a[i] = a[j];
            i = j;
            j = 2 * i;
        }
        else
            j = dx + 1;
    }
    if (i != sx)
        a[i] = nuovo_valore;
}

void stampa_array(int a[],int n)
{
    int i;
    printf("Stampa dell'array ordinato\n");
    for (i=0; i<n; i++)
    {
        printf("%d\n",a[i]);
    }    
}

















