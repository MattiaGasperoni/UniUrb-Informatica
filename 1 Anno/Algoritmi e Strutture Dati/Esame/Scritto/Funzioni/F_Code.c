#include <stdio.h>
#include <stdlib.h>

// Dichiarazione della Struttura Dati Lista
typedef struct elem_lista 
{ 
    int valore; 
    struct elem_lista *succ_p; 
} elem_lista_t; 

void stampa_coda(elem_lista_t *);
void metti_in_coda(elem_lista_t **, elem_lista_t **, int);
elem_lista_t *togli_da_coda(elem_lista_t **,elem_lista_t **);

elem_lista_t* min_coda (elem_lista_t *);
elem_lista_t* max_coda (elem_lista_t *);

int main()
{
    elem_lista_t *ingresso_p = NULL, 
                 *uscita_p   = NULL;

    return (0);
}

void stampa_coda(elem_lista_t *uscita_p)
{
    elem_lista_t *elem_p;
    int i;
    
    i = 1;
    for (elem_p = uscita_p; elem_p != NULL; elem_p = elem_p->succ_p)
    {
        printf("%d. (%d)\n",i,elem_p->valore);
        i++;
    }
}

void metti_in_coda(elem_lista_t **uscita_p, elem_lista_t **ingresso_p, int valore)
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

elem_lista_t* min_coda (elem_lista_t *uscita_p)
{
    elem_lista_t *elem_p, *min_p;
    
    min_p = uscita_p;
    for (elem_p = uscita_p;(elem_p!=NULL);elem_p = elem_p->succ_p)
        if (elem_p->valore<min_p->valore)
            min_p = elem_p;
    return(min_p);
}

elem_lista_t* max_coda (elem_lista_t *uscita_p)
{
    elem_lista_t *elem_p, *max_p;
    
    max_p = uscita_p;
    for (elem_p = uscita_p;(elem_p!=NULL);elem_p = elem_p->succ_p)
        if (elem_p->valore>max_p->valore)
            max_p = elem_p;
    return(max_p);
}
