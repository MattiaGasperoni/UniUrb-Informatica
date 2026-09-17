#include <stdlib.h>
#include <stdio.h>

typedef struct elem_lista 
{
    int valore;
    struct elem_lista *succ_p;
} elem_lista_t;

/* dichiarazione funzioni*/
void stampa_pila(elem_lista_t *);
void metti_su_pila (elem_lista_t **, int);
elem_lista_t *togli_da_pila(elem_lista_t **);

void calcola_maggiori (elem_lista_t *, int);

int main () 
{

    elem_lista_t *cima_p = NULL;

    /*
    Calcola la somma del valore inserito più di recente 
    in P1 con quello inserito più di recente in p2
    */

    /*somma  = togli_da_pila(&cima_p1)->valore + togli_da_pila(&cima_p2)->valore;*/
    return(0);
}

void stampa_pila (elem_lista_t *cima_p) 
{
    elem_lista_t *elem_p;
    int i;
    
    i = 1;
    for (elem_p = cima_p; elem_p != NULL; elem_p = elem_p->succ_p){
        printf("%d. %d\n",i,elem_p->valore);
        i++;
    }
}

void metti_su_pila(elem_lista_t **cima_p, int valore)
{
  elem_lista_t *nuovo_p;
  nuovo_p = (elem_lista_t *)malloc(sizeof(elem_lista_t));
  nuovo_p->valore = valore;
  nuovo_p->succ_p = *cima_p;
  *cima_p = nuovo_p;
}

elem_lista_t *togli_da_pila(elem_lista_t **cima_p)
{
    elem_lista_t *elem_p;
    elem_p = *cima_p;
    if (*cima_p != NULL)
        *cima_p = (*cima_p)->succ_p;
    return(elem_p);
}


/*Acquisisce da tastiera un ulteriore numero intero x e calcola 
tutti valori contenuti all’interno della pila che sono ≥ x*/
void calcola_maggiori (elem_lista_t *cima_p, int x) 
{
    elem_lista_t *elem_p;
    int i;
    
    i = 1;
    for (elem_p = cima_p; elem_p!=NULL; elem_p = elem_p->succ_p){
        if (elem_p->valore >= x){
            printf("%d. %d\n",i,elem_p->valore);
            i++;
        }
    }
}

