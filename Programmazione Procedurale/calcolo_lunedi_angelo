/**************************************************************/
/* Programma per il calcolo della data del Lunedi dell'Angelo */
/**************************************************************/

/*****************************/
/* inclusione delle librerie */
/*****************************/

#include <stdio.h>
#include <string.h>

/********************************/
/* dichiarazione delle funzioni */
/********************************/

int acquisizione_anno(void);

void calcolo_pasqua_gregoriano(int,
                               char*);

void calcolo_pasqua_giuliano(int,
                             char*);

void calcolo_stampa_lunedi(int,
                           int);

/********************************/
/* definizione delle funzioni   */
/********************************/

/*definizione della funzione main*/
int main() 
{
    int anno;  /*input: anno scelto dall'utente*/

    /*ottenimento e validazione stretta dell'anno*/
    anno = acquisizione_anno();

    /*calcolo della Pasqua nel calendario gregoriano*/
    calcolo_pasqua_gregoriano(anno,         
                              "gregoriano");

    /*calcolo della Pasqua nel calendario giuliano*/
    calcolo_pasqua_giuliano(anno,       
                            "giuliano");

    return (0);
}

/*definizione della funzione per acquisire e 
validare un anno nel range specificato (1900-2099)*/
int acquisizione_anno(void)
{
    /*dichiarazione delle variabili locali alla funzione */
    int anno,                /* output: anno scelto dall'utente nel range specificato*/
        esito_lettura,       /* lavoro: esito della scanf */
        acquisizione_errata; /* lavoro: esito complessivo dell’acquisizione */
    
    /*acquisizione e validazione stretta di un anno */
    do
    {   
        printf("\nInserisci un anno compreso tra il 1900 e il 2099: ");
        esito_lettura = scanf("%d",
                              &anno);
        acquisizione_errata = esito_lettura != 1 || anno < 1900 || anno > 2099;
        if (acquisizione_errata)
            printf("\nAnno non accettabile!\n");
        while (getchar() != '\n');
    }
    while (acquisizione_errata);
    return(anno);
}

/*definizione della funzione che calcola 
la data di Pasqua nel calendario gregoriano*/
void calcolo_pasqua_gregoriano(int anno,         /* input: anno scelto dall'utente */
                               char *calendario) /* output: nome calendario */
{
    /*dichiarazione delle variabili locali alla funzione*/
    int a,      /* lavoro: variabile per il calcolo della data di Pasqua*/
        b,      /* lavoro: variabile per il calcolo della data di Pasqua*/
        c,      /* lavoro: variabile per il calcolo della data di Pasqua*/
        d,      /* lavoro: variabile per il calcolo della data di Pasqua*/
        e,      /* lavoro: variabile per il calcolo della data di Pasqua*/
        f,      /* lavoro: variabile per il calcolo della data di Pasqua*/
        g,      /* lavoro: variabile per il calcolo della data di Pasqua*/
        h,      /* lavoro: variabile per il calcolo della data di Pasqua*/
        i,      /* lavoro: variabile per il calcolo della data di Pasqua*/
        k,      /* lavoro: variabile per il calcolo della data di Pasqua*/
        l,      /* lavoro: variabile per il calcolo della data di Pasqua*/
        m,      /* lavoro: variabile per il calcolo della data di Pasqua*/
        mese,   /* output: mese di Pasqua*/
        giorno; /* output: giorno di Pasqua*/

    /*calcolo del mese e del giorno di Pasqua nel calendario gregoriano*/
    a = anno % 19;
    b = anno / 100;
    c = anno % 100;
    d = b / 4;
    e = b % 4;
    f = (b + 8) / 25;
    g = (b - f + 1) / 3;
    h = (19 * a + b - d - g + 15) % 30;
    i = c / 4;
    k = c % 4;
    l = (32 + 2 * e + 2 * i - h - k) % 7;
    m = (a + 11 * h + 22 * l) / 451;
    mese = (h + l - 7 * m + 114) / 31;
    giorno = ((h + l - 7 * m + 114) % 31) + 1;

    /*stampa del menu per il calendario gregoriano*/
    printf("\nIl lunedi dell'Angelo nel calendario %s cade il:\n",
           calendario);

    /*invocazione della funzione per il calcolo del lunedi 
    dell'Angelo e la stampa a caratteri giganti*/
    calcolo_stampa_lunedi(mese,
                          giorno);
}

/*definizione della funzione che calcola 
la data di Pasqua nel calendario giuliano*/
void calcolo_pasqua_giuliano(int anno,         /* input: anno scelto dall'utente */
                             char *calendario) /* output: nome calendario */
{
    /*dichiarazione delle variabili locali alla funzione */
    int a,      /* lavoro: variabile per il calcolo della data di Pasqua*/
        b,      /* lavoro: variabile per il calcolo della data di Pasqua*/
        c,      /* lavoro: variabile per il calcolo della data di Pasqua*/
        d,      /* lavoro: variabile per il calcolo della data di Pasqua*/
        e,      /* lavoro: variabile per il calcolo della data di Pasqua*/
        mese,   /* output: mese di Pasqua*/
        giorno; /* output: giorno di Pasqua*/

    /*calcolo del mese e del giorno di Pasqua nel calendario giuliano*/
    a = anno % 4;
    b = anno % 7;
    c = anno % 19;
    d = (19 * c + 15) % 30;
    e = (2 * a + 4 * b - d + 34) % 7;
    mese = (d + e + 114) / 31;
    giorno = ((d + e + 114) % 31) + 1;

    /*stampa del menu per il calendario giuliano*/
    printf("\nIl lunedi dell'Angelo nel calendario %s cade il: \n", 
           calendario);

    /*invocazione della funzione per il calcolo del lunedi 
    dell'Angelo e la stampa a caratteri giganti*/
    calcolo_stampa_lunedi(mese,
                          giorno);
}

/*definizone della funzione per il calcolo del lunedi 
dell'Angelo e la stampa a caratteri giganti*/
void calcolo_stampa_lunedi(int mese,   /* output: mese del lunedi dell'Angelo*/
                           int giorno) /* output: giono del lunedi dell'Angelo*/
{
    /*dichiarazione delle variabili locali alla funzione */
    int i,             /* lavoro: variabile per lo scorrimento dell'array dei giorni*/              
        j,             /* lavoro: variabile per lo scorrimento dell'array dei mesi*/ 
        prima_cifra,   /* output: prima cifra del giorno */
        seconda_cifra; /* output: seconda cifra del giorno */

    char *pattern_giorni[10][5] = 
    {
        {"*****", "*   *", "*   *", "*   *", "*****"},  
        {"  *  ", " **  ", "* *  ", "  *  ", "*****"},  
        {"*****", "    *", "*****", "*    ", "*****"},  
        {"*****", "    *", "*****", "    *", "*****"},  
        {"*   *", "*   *", "*****", "    *", "    *"},  
        {"*****", "*    ", "*****", "    *", "*****"},  
        {"*****", "*    ", "*****", "*   *", "*****"},  
        {"*****", "   * ", "  *  ", " *   ", "*    "},  
        {"*****", "*   *", "*****", "*   *", "*****"},  
        {"*****", "*   *", "*****", "    *", "*****"}   
    }; /* lavoro: stampa gigante per i numeri da 0 a 9*/
    
    char *pattern_mesi[2][3][5] = 
    {
        {
            {"*   *", "** **", "* * *", "*   *", "*   *"}, /*m*/
            {"  *  ", " * * ", "*****", "*   *", "*   *"}, /*a*/
            {"*****", "*   *", "*****", "*  * ", "*   *"}, /*r*/
        },
        {
            {"  *  ", " * * ", "*****", "*   *", "*   *"}, /*a*/
            {"*****", "*   *", "*****", "*    ", "*    "}, /*p*/
            {"*****", "*   *", "*****", "*  * ", "*   *"}, /*r*/
        }
    }; /* lavoro: stampa gigante per le prime tre lettere dei mesi di marzo e aprile*/
    
    /*ottenimente mese e giorno del lunedi dell'Angelo,
    verifica se la Pasqua cade l'ultimo di marzo*/
    if (mese == 3)
    {
        if (giorno < 31)
        {
            /*ottenimento lunedi dell'Angelo*/
            mese = 3;
            giorno++;  
        }
        else
        {
            /*passaggio al primo di aprile*/
            mese = 4;  
            giorno = 1;
        }
    }
    else 
    {
        giorno++;
    }

    

    /*ciclo for per la stampa a caratteri giganti usando il pattern corrispondente*/
    for (i = 0;
         (i < 5);
         ++i)
    {
        /*stampa del giorno se ha una sola cifra*/
        if (giorno <= 9) 
        {
            printf("%s     ",
                   pattern_giorni[giorno][i]);
        } 
        /*stampa del giorno se ha due cifre*/
        else 
        {
            /*calcolo della prima e della secoda cifra del giorno*/
            prima_cifra = giorno / 10;
            seconda_cifra = giorno % 10;

            printf("%s %s     ",
                   pattern_giorni[prima_cifra][i], 
                   pattern_giorni[seconda_cifra][i]);
        }
        /*ciclo for per la stampa delle prime tre lettere del mese*/
        for (j = 0;
             (j < 3);
             ++j)
        {
            printf("%s ",
                   pattern_mesi[mese - 3][j][i]);
        }
        /*manda a capo la riga*/
        printf("\n");
    }
}
