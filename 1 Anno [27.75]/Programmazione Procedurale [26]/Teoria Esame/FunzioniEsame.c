/****************************/
/*Inclusioni librerie       */                              
/****************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/******************************/
/*Dichiarazione delle funzioni*/                              
/******************************/

void stampa_mese(void);
void stampa_giorni(void);
void estrai_numeri_stringa(char *);
void stampa_numeri_dispari(int,int);
void stampa_numeri_pari(int,int);
int biimplicazione(int,int);

/****************************************/
/*Dichiarazione delle Funzioni Ricorsive*/                              
/****************************************/

int conta_cifre_pari(int);
int conta_cifre_dispari(int);
int conta_0_5(int);
int minuscole_stringa(char *);
int maiuscole_stringa(char *);
int lunghezza_stringa(char *);
int fattoriale(int);

/***************/
/*Funzione main*/
/***************/

int main (void)
{
    /*Funzione per la stampa dei mesi dell'anno*/
    /*stampa_mese();*/

    /*Funzione per la stampa dei giorni della settimana*/
    /*stampa_giorni();*/

    /*Funzione che data una stringa con dei numeri li prende e li stampa*/
    /*char *str = "3.14 2.718 1.618";
    estrai_numeri_stringa(str);*/

    /*Funzione che dati 2 numeri stampa tutti i numeri dispari e pari tra i due numeri*/
    /*int n1 = 10;
    int n2 = 106;
    stampa_numeri_dispari(n1,n2);
    stampa_numeri_pari(n1,n2);*/

    /*Biimplicazione logica, se sono entrambi o veri o entrambi falsi stampa vero*/
    /*int n1 = 0;
    int n2 = 1;
    printf("%d ", biimplicazione(n1,n2));*/

    /**************************************/
    /*Invocazioni delle Funzioni Ricorsive*/                              
    /**************************************/

    /*Funzioni ricorsiva che conta le cifre pari e dispari in un numero*/
    /*int n = 20;
    printf("Il numero di cifre pari presenti in %d: %d\n", n, conta_cifre_pari(n));
    printf("Il numero di cifre dispari presenti in %d: %d\n", n, conta_cifre_dispari(n));*/

    /*Funzione ricorsiva che ti dice il numero di cifre che sono uguali a 0 e 5*/
    int n = 25; 
    printf("Il numero di cifre uguali a 0 o 5 in %d sono: %d\n", n, conta_0_5(n));
    
    /*Funzione ricorsiva per il calcolo del fattoriale*/
    /*int n = 7;
    printf("Il fattoriale di %d : %d\n", n, fattoriale(n));*/

    /*Funzioni ricorsiva che data una stringa ti dici quanti caratteri sono in totale e quanti minuscoli e maiuscoli*/
    /*char *str = "snbsabdwGYHUVYV";
    printf("Le minuscole nella stringa : %d\n", minuscole_stringa(str));
    printf("Le maiuscole nella stringa : %d\n", maiuscole_stringa(str));
    printf("La lunghezza della stringa : %d\n", lunghezza_stringa(str));*/
    
    

    return(0);
}

/****************************/
/*Definizione delle funzioni*/                              
/****************************/

/*Scrivere una funzione C con il minuer numero n > 1 di istruzione (da non confondere con le dichiarazioni
locali), che stampa i nomi dei 12 mesi dell'anno */
void stampa_mese(void)
{
    int i;
    char *mese[] = {  "Gennaio",
                           "Febbraio",
                           "Marzo",
                           "Aprile",
                           "Maggio",
                           "Giugno",
                           "Luglio",
                           "Agosto",
                           "Settembre",
                           "Ottobre",
                           "Novembre",
                           "Dicembre"
                        };

    for(i = 0; i < 12; i++)
    {
        printf("%s\n",mese[i]);
    }
}

/*Scrivere una funzione C con il minuer numero n > 1 di istruzione (da non confondere con le dichiarazioni
locali), che stampa i nomi dei 7 gionri della settimana*/
void stampa_giorni(void)
{
    int i;
    char *settimana[] = { "lunedi",
                           "martedi",
                           "mercoledi",
                           "giovedi",
                           "venerdi",
                           "sabato",
                           "domenica"
                        };

    for(i = 0; i < 7; i++)
    {
        printf("%s\n",settimana[i]);
    }
}

/*Scrivere una funzione in C il cui parametro è una stringa contenente tre numeri reali, 
che li estrae dalla stringa e li pone in tre parametri di output.*/
void estrai_numeri_stringa(char *str)
{
    double n1,
           n2,
           n3;

    sscanf(str,
           "%lf %lf %lf", 
            &n1, &n2, &n3);

    printf("I tre valori sono: %f - %f - %f",n1,n2,n3);
}

/*Scrivere una funzione C in cui unici parametri sono due numeri naturali,
che stampa tutti i numeri naturali dispari compresi tra i due numeri dati*/
void stampa_numeri_dispari(int num1, int num2) 
{
    // Stampa i numeri dispari compresi tra num1 e num2
    printf("Numeri dispari tra %d e %d sono:\n", num1, num2);
    for (int i = num1; i <= num2; i++) 
    {
        if (i % 2 != 0) 
        {
            printf("%d\n", i);
        }
    }
}

/*Scrivere una funzione C in cui unici parametri sono due numeri naturali,
che stampa tutti i numeri naturali pari compresi tra i due numeri dati*/
void stampa_numeri_pari(int num1, int num2) 
{
    // Stampa i numeri pari compresi tra num1 e num2
    printf("Numeri pari tra %d e %d sono:\n", num1, num2);
    for (int i = num1; i <= num2; i++) 
    {
        if (i % 2 == 0) 
        {
            printf("%d\n", i);
        }
    }
}

/*Scrivere una funzione C i cui gli unici parametri sono due interi da interpretare come valori di verità, che
restituisce 0 o 1 a seconda che la loro biimplicazione logica sia falsa o vera.*/
int biimplicazione(int v1,int v2)
{
    int biimplicazione;
    biimplicazione = (v1 == v2 || (v1 != 0 && v2 != 0))? 1 : 0;
    return (biimplicazione);
}

/**************************************/
/*Definizione delle Funzioni ricorsive*/
/**************************************/

/*Scrivere una funzione C ricorsiva, il cui unico parametro è un naturale (int), 
che restituisce il numero delle cifre pari presenti*/
int conta_cifre_pari(int n)
{
    int conteggio, ultima_cifra;

    // Caso base: n è 0, non ci sono cifre da controllare
    if (n == 0) 
        conteggio = 0;
    else
    {
        // Estrapolo l'ultima cifra di n
        ultima_cifra = n % 10;

        // Se l'ultima cifra di n è pari, incremento il conteggio
        conteggio = (ultima_cifra % 2 == 0)? 1 : 0;

        // Ricorsione sulla parte restante di n
        conteggio += conta_cifre_pari(n / 10);
        
    }
    return conteggio;
}

/*Scrivere una funzione C ricorsiva, il cui unico parametro è un naturale (int), 
che restituisce il numero delle cifre dispari presenti*/
int conta_cifre_dispari(int n)
{
    int conteggio, ultima_cifra;

    // Caso base: n è 0, non ci sono cifre da controllare
     
    conteggio = 0;
    if (n != 0)
    {
        // Estrapolo l'ultima cifra di n
        ultima_cifra = n % 10;

        // Se l'ultima cifra di n è dispari, incremento il conteggio
        conteggio = (ultima_cifra % 2 != 0)? 1 : 0;

        // Ricorsione sulla parte restante di n
        conteggio += conta_cifre_dispari(n / 10);
        
    }
    return conteggio;
}

/*Scrivere una funzione C ricorsiva, il cui unico parametro è un naturale(int),
che restituisce il numero di cifre presenti che sono uguali a 0 o a 5*/
int conta_0_5(int n)   /*PORCO DIO se metti 0 non funziona*/
{
    int conteggio, ultima_cifra;
    conteggio = 0;
    if (n != 0)
    {
        // Estrapolo l'ultima cifra di n
        ultima_cifra = n % 10;

        // Se l'ultima cifra di n è uguale a 5 o 0, incremento il conteggio
        conteggio = (ultima_cifra == 5 || ultima_cifra == 0)? 1 : 0;

        // Ricorsione sulla parte restante di n
        conteggio += conta_0_5(n / 10);
    }

        
    return conteggio;
}

/*Scrivere una funzione C ricorsiva il cui unico parametro è un naturale(int),
che restituisce il suo fattoriale*/
int fattoriale(int n)
{
    int fatt; /* output: risultato */
    if (n == 0)
        fatt = 1;
    else
        fatt = n * fattoriale(n - 1);
    return(fatt);
}

/*Scrivere una funzione C ricorsiva il cui unico parametro è una stringa, che restituisce 
come risultato il numero di lettere minuscole presenti in essa*/
int minuscole_stringa( char *str) 
{
    int lettere = 0;
    if (*str != '\0') 
    {
        lettere = islower((unsigned char)*str) ? 1 : 0;
        lettere += minuscole_stringa(str + 1);
    }    
    return lettere;
}
/*Scrivere una funzione C ricorsiva il cui unico parametro è una stringa, che restituisce 
come risultato il numero di lettere maiuscole presenti in essa*/
int maiuscole_stringa( char *str) 
{
    int lettere = 0;
    if (*str != '\0') 
    {
        lettere = isupper((unsigned char)*str) ? 1 : 0;
        lettere += maiuscole_stringa(str + 1);
    }    
    return lettere;
}

/*Scrivere una funzione C ricorsiva il cui unico parametro è una stringa, che restituisce 
la lunghezza della stringa*/
int lunghezza_stringa( char *str) 
{
    int lunghezza = 0;
    if (*str != '\0') 
    {
        lunghezza = 1 + lunghezza_stringa(str + 1);
    }
    
    return lunghezza;
}

/*Scrivere una funzione C ricorsiva il cui unico parametro è la testa di una lista e restituisce
la lunghezza della lista*/

/*Scrivere una funzione ricorsiva in C che ha come parametri di ingresso una stringa e un
carattere e restituisce come risultato il numero di occorrenze del carattere all’interno della stringa.*/
/*int carattere_in_stringa(char *s,char c)
{
    int n;
    if (s[0] == "\0")
        n = 0;
    else
    {
        n = (s[0] == c)? 1 : 0;
        n += count(s + 1,c);
    }
    return(n);
}*/