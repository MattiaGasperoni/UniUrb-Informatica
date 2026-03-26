#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*dichirazione delle strutture dati*/
typedef struct elem_lista 
{ 
    int valore; 
    struct elem_lista *succ_p; 
} elem_lista_t;

/*dichiarazioni delle funzioni per le strutture dati*/
void lista();
void pila();
void coda();

int  validazione(void);
void popola(elem_lista_t**, int);

/*funzioni liste*/
void visita_lista(elem_lista_t *);
int rimuovi_da_lista_ordinata(elem_lista_t **,int);
int inserisci_in_lista_ordinata(elem_lista_t **,int);

/*funzioni pile*/
void metti_su_pila(elem_lista_t **,int);
elem_lista_t *togli_da_pila(elem_lista_t **cima_p);

/*funzioni code*/
void metti_in_coda(elem_lista_t **,elem_lista_t **,int);
elem_lista_t *togli_da_coda(elem_lista_t **,elem_lista_t **);

int main()
{
    int obbiettivo;

    /*Start tempo*/
    clock_t t1,t2;
    double cpu_time;
    t1 = clock();
    

    printf("Digita che struttura dati vuoi eseguire\n1-Lista Ordinata, 2-Pila, 3-Coda : ");
    scanf("%d", &obbiettivo);

    switch (obbiettivo)
    {
        case 1:
            lista();
        break;   
        
        case 2:
            pila();
        break;    
        
        case 3:
            coda();
        break;   
    }

    /*fine tempo*/
    t2 = clock();
    cpu_time = ((double) (t2 - t1)) / CLOCKS_PER_SEC;
    printf("\n\nTempo per l'esecuzione del programma = %f secondi \n",cpu_time);

    return 0;
}

/*Lista*/
void lista()
{
    int obbiettivo,valore,n,i;
    

    /*Allocazione di Memoria e creazione Lista*/
    elem_lista_t *testa = NULL;
    n = validazione();
    for(i = 0; i < n; i++)
    {
        inserisci_in_lista_ordinata(&testa, i);
    }
    
    /*Stampa Lista originale*/
    visita_lista(testa); 

    printf("\n\nCosa vuoi fare con la Lista?\nDigita 1 per rimuovere un elemento o 2 per aggiungere un elemento : ");
    scanf("%d", &obbiettivo);
    if (obbiettivo == 1)
    {
        printf("Che valore vuoi rimuovere?: ");
        scanf("%d", &valore);
        rimuovi_da_lista_ordinata(&testa,valore);
    }
    else
    {
        printf("Che valore vuoi aggiungere?: ");
        scanf("%d", &valore);
        inserisci_in_lista_ordinata(&testa,valore);
    }
    visita_lista(testa); 
}

/*Pila*/
void pila()
{
    int obbiettivo,valore,n,i;
    

    /*Allocazione di Memoria e creazione Pila*/
    elem_lista_t *cima = NULL;
    n = validazione();
    for(i = 0; i < n; i--)
    {
        inserisci_in_lista_ordinata(&cima, i);
    }
    
    /*Stampa Lista originale*/
    visita_lista(cima); 

    printf("\n\nCosa vuoi fare con la Pila?\nDigita 1 per rimuovere n elementi o 2 per aggiungere un elemento : ");
    scanf("%d", &obbiettivo);
    if (obbiettivo == 1)
    {
        printf("Quanti valori vuoi rimuovere?: ");
        scanf("%d", &valore);
        for(i = 0; i < valore; i++)
        {
            togli_da_pila(&cima);
        } 
    }
    else
    {
        printf("Che valore vuoi aggiungere?: ");
        scanf("%d", &valore);
        metti_su_pila(&cima,valore);
    }

    /*Stampa Lista Modificata*/
    visita_lista(cima); 
}

/*Coda*/
void coda()
{

}

/*Validazione input*/
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

/*Funzione per popolare la lista ordinata*/
void popola(elem_lista_t** testa_p, int n) 
{
    int i;
    for(i = 0; i < n; i++)
    {
        inserisci_in_lista_ordinata(testa_p, i);
    }
}

/*Funzione per stampare la lista*/
void visita_lista(elem_lista_t *testa_p)
{
    elem_lista_t *elem_p;

    for (elem_p = testa_p; elem_p != NULL; elem_p = elem_p->succ_p)
        printf("%d ", elem_p->valore);
}

/*Funzione per inserire un elemento nella lista*/
int inserisci_in_lista_ordinata(elem_lista_t **testa_p,int valore)
{
    int inserito;
    elem_lista_t *corr_p,*prec_p,*nuovo_p;

    for (corr_p = prec_p = *testa_p;
        ((corr_p != NULL) && (corr_p->valore < valore));
        prec_p = corr_p, corr_p = corr_p->succ_p);
    if ((corr_p != NULL) && (corr_p->valore == valore))
        inserito = 0;
    else
    {
        inserito = 1;
        nuovo_p = (elem_lista_t *)malloc(sizeof(elem_lista_t));
        nuovo_p->valore = valore;
        nuovo_p->succ_p = corr_p;
        if (corr_p == *testa_p)
            *testa_p = nuovo_p;
        else
            prec_p->succ_p = nuovo_p;
    }
    return(inserito);
}

/*Funzione per rimuovere un elemento nella lista*/
int rimuovi_da_lista_ordinata(elem_lista_t **testa_p,int valore)
{
    int rimosso;
    elem_lista_t *corr_p,*prec_p;

    for (corr_p = prec_p = *testa_p;
        ((corr_p != NULL) && (corr_p->valore < valore));
        prec_p = corr_p, corr_p = corr_p->succ_p);
    if ((corr_p == NULL) || (corr_p->valore > valore))
        rimosso = 0;
    else
    {
        rimosso = 1;
        if (corr_p == *testa_p)
            *testa_p = corr_p->succ_p;
        else
            prec_p->succ_p = corr_p->succ_p;
        free(corr_p);
    }
    return(rimosso);
}

/*Funzione per inserire un elemento nella coda*/
void metti_in_coda(elem_lista_t **uscita_p,elem_lista_t **ingresso_p,int valore)
{
    elem_lista_t *nuovo_p;

    nuovo_p = (elem_lista_t *)malloc(sizeof(elem_lista_t));
    nuovo_p->valore = valore;
    nuovo_p->succ_p = NULL;
    if (*ingresso_p != NULL)
        (*ingresso_p)->succ_p = nuovo_p;
    else
        *uscita_p = nuovo_p;
    *ingresso_p = nuovo_p;
}

/*Funzione per rimuovere un elemento nella coda*/
elem_lista_t *togli_da_coda(elem_lista_t **uscita_p,elem_lista_t **ingresso_p)
{
    elem_lista_t *elem_p;

    elem_p = *uscita_p;
    if (*uscita_p != NULL)
    {
        *uscita_p = (*uscita_p)->succ_p;
        if (*uscita_p == NULL)
            *ingresso_p = NULL;
    }
    return(elem_p);
}

/*Funzione per inserire un elemento nella pila*/
void metti_su_pila(elem_lista_t **cima_p,int valore)
{
    elem_lista_t *nuovo_p;

    nuovo_p = (elem_lista_t *)malloc(sizeof(elem_lista_t));
    nuovo_p->valore = valore;
    nuovo_p->succ_p = *cima_p;
    *cima_p = nuovo_p;
}

/*Funzione per rimuovere un elemento nella pila*/
elem_lista_t *togli_da_pila(elem_lista_t **cima_p)
{
    elem_lista_t *elem_p;

    elem_p = *cima_p;
    if (*cima_p != NULL)
        *cima_p = (*cima_p)->succ_p;
    return(elem_p);
}
