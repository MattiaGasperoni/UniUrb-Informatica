#include <stdio.h>
#include <stdlib.h>


typedef struct nodo_albero_bin
{
int valore;                               /*valore nel nodo ATTENZIONE AL TIPO*/
    struct nodo_albero_bin *sx_p, *dx_p;  /*puntatore al figlio sinistro e al destro*/
} nodo_albero_bin_t;

void visita_albero_bin_post(nodo_albero_bin_t *nodo_p);
nodo_albero_bin_t *cerca_in_albero_bin_ric(nodo_albero_bin_t *,int);
int inserisci_in_albero_bin_ric(nodo_albero_bin_t **, int); /* ** passare per indirizzo*/

int main()
{
    /*Dichiarazione Elemento Pricipale*/
    nodo_albero_bin_t *radice_p = NULL;

    return(0);
}

void visita_albero_bin_post(nodo_albero_bin_t *nodo_p)
{
    if (nodo_p != NULL) 
    {
        visita_albero_bin_post(nodo_p->sx_p);
        visita_albero_bin_post(nodo_p->dx_p);
        printf("%f\n",nodo_p->valore);
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
    return(nodo_p);
}

int inserisci_in_albero_bin_ric(nodo_albero_bin_t **radice_p, int valore) 
{
    int inserito;
    nodo_albero_bin_t *nodo_p, 
                      *padre_p,
                      *nuovo_p;

    for (nodo_p = padre_p = *radice_p;
         nodo_p != NULL && nodo_p->valore != valore; 
         padre_p = nodo_p, nodo_p = (valore < nodo_p->valore) ? nodo_p->sx_p : nodo_p->dx_p);

    if (nodo_p != NULL) 
    {
        inserito = 0;   /*Il valore esiste già nell'albero*/
    } 
    else 
    {
        inserito = 1;  /*Il valore non esiste, dobbiamo inserirlo*/
        nuovo_p = (nodo_albero_bin_t *)malloc(sizeof(nodo_albero_bin_t));
        nuovo_p->valore = valore;
        nuovo_p->sx_p = nuovo_p->dx_p = NULL;

        /*if che verifica se l'albero sia vuoto*/
        if (*radice_p == NULL)           
        {
            /*se vuoto, il nuovo nodo diventa la radice*/
            *radice_p = nuovo_p;          
        } 
        /*se l'albero non e' vuoto confronta il valore da inserire con quello nel nodo*/
        else if (valore < padre_p->valore)  
        {
            /*Inserisci come figlio sinistro se < del nodo padre */
            padre_p->sx_p = nuovo_p;  
        } 
        else 
        {
            /*Inserisci come figlio destro se > del nodo padre*/
            padre_p->dx_p = nuovo_p;  
        }
    }

    return inserito;
}

/* Acquisisce da tastiera un numero reale x e calcola tutti 
valori contenuti all’interno dell’albero che sono ≤ x*/
void calcola_min(nodo_albero_bin_t *nodo_p, double x)
{
    if (nodo_p != NULL) {
        calcola_min(nodo_p->sx_p, x);
        calcola_min(nodo_p->dx_p, x);
        if (nodo_p->valore <= x)
            printf("%f\n",nodo_p->valore);
    }
}
