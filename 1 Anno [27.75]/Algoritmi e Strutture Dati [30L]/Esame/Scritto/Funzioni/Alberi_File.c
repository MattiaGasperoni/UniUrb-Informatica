#include <stdlib.h>
#include <stdio.h>

/* dichiarazione strutture*/

typedef struct nodo_albero_bin {
    int valore;
    struct nodo_albero_bin *sx_p, *dx_p;
} nodo_albero_bin_t;


/* dichiarazione funzioni*/
int inserisci_in_albero_bin_ric(nodo_albero_bin_t **radice_p, int dato);
void visita_albero_bin_simm(nodo_albero_bin_t *nodo_p);


/* programma main */
int main (int argc, char **argv) {
    int N, i, dato, esito;
    nodo_albero_bin_t *radice_p;
    char fname[9] = "dati.txt";
    FILE *fid;
    
    radice_p = NULL;
    fid = fopen(fname, "r");
    printf("Lettura file...\n");
    fscanf(fid, "%d",&N);
    printf("numero dati attesi N = %d\n",N);
    i = 0;
    
    for (i=0;i<N;i++){
        fscanf(fid, "%d",&dato);
        printf("%d. %d\n", i+1, dato);
        esito = inserisci_in_albero_bin_ric(&radice_p, dato);
        if (esito == 0)
            printf("Valore duplicato non inserito\n");
    }
    printf("...dati inseriti in albero.\n\n");
    printf("visita in ordine simmetrico dell'albero...\n");
    visita_albero_bin_simm(radice_p);
    
    return(0);
}

                    
/* definizione funzioni */

int inserisci_in_albero_bin_ric(nodo_albero_bin_t **radice_p, int dato){
    int inserito;
    nodo_albero_bin_t *nodo_p, *padre_p, *nuovo_p;
    
    for (nodo_p = padre_p = *radice_p; 
        ((nodo_p!=NULL)&&nodo_p->valore!=dato);
        padre_p = nodo_p, nodo_p = (dato < nodo_p->valore)?
                                                    nodo_p->sx_p:
                                                    nodo_p->dx_p);
    if (nodo_p != NULL)
        inserito = 0;
    else {
        inserito = 1; 
        nuovo_p = (nodo_albero_bin_t *)malloc(sizeof(nodo_albero_bin_t));
        nuovo_p->valore = dato;
        nuovo_p->sx_p = nuovo_p->dx_p = NULL;
        if (nodo_p == *radice_p)
            (*radice_p = nuovo_p);
        else
            if (dato < padre_p->valore)
                padre_p->sx_p = nuovo_p;
            else
                padre_p->dx_p = nuovo_p;
    }
    return (inserito) ;
}


void visita_albero_bin_simm(nodo_albero_bin_t *nodo_p){
    if (nodo_p != NULL) {
        visita_albero_bin_simm(nodo_p->sx_p);
        printf("%d\n",nodo_p->valore);
        visita_albero_bin_simm(nodo_p->dx_p);
    }
}