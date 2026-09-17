#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*dichirazione delle strutture dati*/
typedef struct nodo_albero_bin
{
    int valore;
    struct nodo_albero_bin *sx_p, *dx_p;
} nodo_albero_bin_t;

/*dichiarazioni delle funzioni*/
int validazione(void);

void visita_albero_bin_ant(nodo_albero_bin_t *);
void visita_albero_bin_simm(nodo_albero_bin_t *);
void visita_albero_bin_post(nodo_albero_bin_t *);

int inserisci_in_albero_bin_ric(nodo_albero_bin_t **,int);
nodo_albero_bin_t *cerca_in_albero_bin_ric(nodo_albero_bin_t *,int);

int main()
{
    int n,i,obbiettivo,valore;
    /*Start tempo*/
    clock_t t1,t2;
    double cpu_time;
    t1 = clock();
    
    /*Allocazione di Memoria e creazione albero*/
    nodo_albero_bin_t *nodo = NULL;
    n = validazione();

    srand(time(NULL)); 
    /*Generatore di numeri casuali tra 1 e n*/
    for(i = 0; i < n ; i++)
    {
        inserisci_in_albero_bin_ric(&nodo,rand() % 100);
    }


    /*Stampa albero originale*/
    visita_albero_bin_ant(nodo);


    printf("\n\nCosa vuoi fare con l albero?\nDigita 1 per visitare l albero , 2 per aggiungere un elemento , 3 per cercarne uno: ");
    scanf("%d", &obbiettivo);
    if (obbiettivo == 1)
    {
        printf("\nDigita che visita vuoi effettuare 1-ant , 2-sim , 3-post , 4 tutte e tre: ");
        scanf("%d", &valore);

        switch (valore)
        {
            case 1:
                printf("\n");
                visita_albero_bin_ant(nodo);
                printf("\n");

            break;   
            
            case 2:
                printf("\n");
                visita_albero_bin_simm(nodo);
                printf("\n");
            break;    
            
            case 3:
                visita_albero_bin_post(nodo);
            break;   
            
            case 4:
                printf("\nAnteriore:  ");
                visita_albero_bin_ant(nodo);
                printf("\nSimmetrica: ");
                visita_albero_bin_simm(nodo);
                printf("\nPosteriore: ");
                visita_albero_bin_post(nodo);
                printf("\n");
            break;   
        }
    }
    else if (obbiettivo == 2)
    {
        printf("Che valore vuoi aggiungere?: ");
        scanf("%d", &valore);
        inserisci_in_albero_bin_ric(&nodo, valore);
    }
    else
    {
        printf("Che valore vuoi cercare?: ");
        scanf("%d", &valore);
        cerca_in_albero_bin_ric(nodo, valore);
    }

    

    /*fine tempo*/
    t2 = clock();
    cpu_time = ((double) (t2 - t1)) / CLOCKS_PER_SEC;
    printf("\n\nTempo per l'esecuzione del programma = %f secondi \n",cpu_time);

    return 0;
}

/*definizione delle funzioni*/

int validazione(void)
{
    
    int n,                
        esito_lettura,       /* lavoro: esito della scanf */
        acquisizione_errata; /* lavoro: esito complessivo dell’acquisizione */
    
    /*acquisizione e validazione stretta di un anno */
    do
    {   
        printf("\nQuanti elementi ha?: ");
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


void visita_albero_bin_ant(nodo_albero_bin_t *nodo_p)
{
    if (nodo_p != NULL)
    {
        printf("%d ", nodo_p->valore);
        visita_albero_bin_ant(nodo_p->sx_p);
        visita_albero_bin_ant(nodo_p->dx_p);
    }
}

void visita_albero_bin_simm(nodo_albero_bin_t *nodo_p)
{
    if (nodo_p != NULL)
    {
        visita_albero_bin_simm(nodo_p->sx_p);
        printf("%d ", nodo_p->valore);
        visita_albero_bin_simm(nodo_p->dx_p);
    }
}

void visita_albero_bin_post(nodo_albero_bin_t *nodo_p)
{
    if (nodo_p != NULL)
    {
        visita_albero_bin_post(nodo_p->sx_p);
        visita_albero_bin_post(nodo_p->dx_p);
        printf("%d ", nodo_p->valore);
    }
}

nodo_albero_bin_t *cerca_in_albero_bin_ric(nodo_albero_bin_t *radice_p,int valore)
{
    nodo_albero_bin_t *nodo_p;

    for (nodo_p = radice_p;
    ((nodo_p != NULL) && (nodo_p->valore != valore));
    nodo_p = (valore < nodo_p->valore)?
        nodo_p->sx_p:
        nodo_p->dx_p);
    if (nodo_p != NULL)
        printf("Valore presente nell albero ");
    else
        printf("Valore NON presente nell albero ");
    return(nodo_p);
}

int inserisci_in_albero_bin_ric(nodo_albero_bin_t **radice_p,int valore)
{
    int inserito;
    nodo_albero_bin_t *nodo_p,*padre_p,*nuovo_p;

    for (nodo_p = padre_p = *radice_p;
        ((nodo_p != NULL) && (nodo_p->valore != valore));
        padre_p = nodo_p, nodo_p = (valore < nodo_p->valore)?
            nodo_p->sx_p:
            nodo_p->dx_p);
    if (nodo_p != NULL)
        inserito = 0;

    else
    {
        inserito = 1;
        nuovo_p = (nodo_albero_bin_t *)malloc(sizeof(nodo_albero_bin_t));
        nuovo_p->valore = valore;
        nuovo_p->sx_p = nuovo_p->dx_p = NULL;
        if (nodo_p == *radice_p)
            *radice_p = nuovo_p;
        else
            if (valore < padre_p->valore)
                padre_p->sx_p = nuovo_p;
        else
            padre_p->dx_p = nuovo_p;
    }
    return(inserito);
}
