#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* dichiarazione strutture*/

typedef struct elem_lista {
    char val[6];
    struct elem_lista *succ_p;
} elem_lista_t;

/* dichiarazione funzioni*/
void metti_in_coda (elem_lista_t **uscita_p, elem_lista_t **ingresso_p, char valore[]);
void stampa_coda (elem_lista_t *uscita_p);
elem_lista_t* cerca_in_coda (elem_lista_t *uscita_p, char key[]);


/* programma main */
int main (int argc, char **argv) {
    FILE *fid;
    char fname[9] = "dati.txt";
    int N, i;
    char key[6], dato[6];
    elem_lista_t *uscita_p, *ingresso_p, *elem_p;
    
    uscita_p = ingresso_p = NULL;
    fid = fopen(fname, "r");
    printf("Lettura file...\n");
    fscanf(fid, "%d",&N);
   
    for (i=0;i<N;i++){
        fscanf(fid, "%s\n",dato);
        printf("Dato acquisito: %s\n", dato);
        metti_in_coda(&uscita_p,&ingresso_p, dato);
        printf("...e inserito in coda\n\n");
    }
    printf("Stampa del contenuto della coda...\n");
    stampa_coda(uscita_p);
    printf("\n");
    printf("key = ");
    scanf("%s",key);
    elem_p = cerca_in_coda(uscita_p,key);
    if (elem_p!=NULL)
        printf("Trovato elemento %s\n",elem_p->val);
    else
        printf("Elemento non trovato.\n");
    return(0);
}

/* definizione funzioni */
void metti_in_coda(elem_lista_t **uscita_p,
                   elem_lista_t **ingresso_p,
                   char valore[]) {
    
    elem_lista_t *nuovo_p;
    nuovo_p = (elem_lista_t *)malloc(sizeof(elem_lista_t));
    strcpy(nuovo_p->val,valore);
    nuovo_p->succ_p = NULL;
    if (*ingresso_p != NULL)
        (*ingresso_p)->succ_p = nuovo_p;
    else
        *uscita_p = nuovo_p;
    *ingresso_p = nuovo_p;
}

elem_lista_t* cerca_in_coda (elem_lista_t *uscita_p, char key[]){
    elem_lista_t *elem_p;
    
    for (elem_p = uscita_p;((elem_p!=NULL)&&(strcmp(elem_p->val,key)!=0));elem_p = elem_p->succ_p);
    return(elem_p);
}

void stampa_coda (elem_lista_t *uscita_p) {
    elem_lista_t *elem_p;
    int i;
    
    i = 1;
    for (elem_p = uscita_p; elem_p!=NULL; elem_p = elem_p->succ_p){
        printf("%d. %s\n",i,elem_p->val);
        i++;
    }
}


