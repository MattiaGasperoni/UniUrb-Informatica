#include <stdio.h>
#include <stdlib.h>

//Dichiarazione della Struttura Dati Lista
typedef struct elem_lista 
{ 
    int valore; 
    struct elem_lista *succ_p; 
} elem_lista_t; 

//Dichiuarazioni funzioni liste
void stampa_lista(elem_lista_t *);
elem_lista_t *cerca_in_lista(elem_lista_t *,int);
int inserisci_in_lista_ordinata(elem_lista_t **,int);
void inserisci_in_lista (elem_lista_t **, int);


int main()
{
    /*Dichiarazione Elemento Pricipale*/
    elem_lista_t *testa_p = NULL;

    return(0);
}

void stampa_lista(elem_lista_t *testa_p)
{
    elem_lista_t *elem_p;

    for (elem_p = testa_p;
        (elem_p != NULL);
        elem_p = elem_p->succ_p)
        printf(" %d -",elem_p->valore);
}

elem_lista_t *cerca_in_lista(elem_lista_t *testa_p,int valore)
{
    elem_lista_t *elem_p;

    for (elem_p = testa_p;
        ((elem_p != NULL) && (elem_p->valore != valore));
        elem_p = elem_p->succ_p);
    return(elem_p);
}

/*Funzione per inserire un elemento nella lista in maniera ordniata (crescente)*/
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

void inserisci_in_lista (elem_lista_t **testa_p, int dato)
{
    elem_lista_t *nuovo_p;
    
    nuovo_p = (elem_lista_t *)malloc(sizeof(elem_lista_t));
    nuovo_p->valore = dato;
    /* inserimento direttamente in testa dato che i valori 
    sono presi da un array ordinato*/
    nuovo_p->succ_p = *testa_p; 
    *testa_p = nuovo_p;
}
