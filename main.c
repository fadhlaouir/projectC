#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct typeDuBien typeDuBien;
struct typeDuBien
{
    char *code;
    char *libelle;
    float prix;
};

typedef struct receipt receipt;
struct receipt
{
    char receiptLibelle[20], receiptCode[6];
    float receiptPrix, S;
    int minSupp;
};

static typeDuBien biens[] =
    {

        {"00712", "bol", 25.00},  
        {"123", "jus", 1.35},    
        {"654", "chocolat", 2.78},
        {"763", "crevette", 33.62},
        {"34", "serviette_papier", 0.87},
    	{"00310", "Poulette", 35.00},
        {"00322", "Du boeuf", 45.00},
        {"167", "fromage", 1.55},
        {"00323", "Poisson", 40.00},
        {"00510", "T-shirt", 75.00},
        {"1009", "creme_glacee", 3.56},
        {"00511", "Pantalon", 120.00},
        {"00512", "Manteau", 100.00},
        {"00513", "Sauteuse", 85.00},
        {"500", "lait", 0.97},
        {"890", "coca", 1.22},
        {"00710", "Agresser", 15.50},
        {"00711", "Poêle à frire", 200.00},
};

static int bienstotale = sizeof(biens) / sizeof(biens[0]);

void afficher_tab()
{
    int i;

    for (i = 0; i < bienstotale; i++)
    printf("%s %s %f\n", biens[i].code, biens[i].libelle, biens[i].prix);
    printf("\n Nombres totales des biens: %d\n", bienstotale);
}



int main(void)

{

    unsigned int i, j, minSupp;
    char tempCode[6]; //code entrer
    receipt receipt[13];

    char stop[2] = {"F"}; //sorter du programme
    float ttlcost = 0;    //resultat final

    unsigned int total = 0; //nbr de produit dans le tableaux
               FILE *bdt;                  //file bdt
    FILE *idt;              //file identi
    FILE *rslt;             //file resultat

    //files
  bdt = fopen("Bdt.txt", "a");
    idt = fopen("identifiant.txt", "a"); /* identifiant.txt*/
    rslt = fopen("resultat.txt", "a");

    afficher_tab();

    while (strcmp(tempCode, stop))
    { //strcmp comparer entre 2 string
        printf("\n Veuillez saisir le code article. Tapez F pour terminer: ");
        scanf("%s", tempCode);
        printf("Donner nombre de produits: ");
        scanf("%d", &minSupp); //qtt

        for (i = 0; i < bienstotale; ++i)
        {
            if (strcmp(tempCode, biens[i].code) == 0)
            {
                strcpy(receipt[total].receiptLibelle, biens[i].libelle); //strcpy copy
                strcpy(receipt[total].receiptCode, biens[i].code);
                receipt[total].receiptPrix = biens[i].prix;
                receipt[total].S = biens[i].prix * minSupp;
                receipt[total].minSupp = minSupp;
                ttlcost += receipt[total].S;
                total++;
            }
        }
    }
    printf("_____________________________________\n\n");
    printf("      MERCI DE VOTRE VISITE!     \n");
    printf("_____________________________________\n");
    printf("         Voici votre reçu:       \n\n");
    printf("%30s %20s %20s %20s %20s", " Libelle ", " Code ", " Prix ", " QTT", " Supp\n");

    for (j = 0; j < total; ++j)
    {
        printf("%30s %20s %20.2f %20d %20.2f\n", receipt[j].receiptLibelle, receipt[j].receiptCode, receipt[j].receiptPrix, receipt[j].minSupp, receipt[j].S);
        fprintf(idt, "%10s%10s%10.2f\n", receipt[j].receiptCode, receipt[j].receiptLibelle, receipt[j].receiptPrix);                                                  //for identifiant
                              fprintf(bdt, "%10s\n", receipt[j].receiptCode);       /* Bdt.txt*/ //"a" for contenu typing "w" for deleting and put new ligne                                                                                                                                      //        fprintf(bdt, "%10s\n", receipt[j].receiptCode);                                                                                                              //for Bdt
        fprintf(rslt, "%10s %10s %10.2f %10d %10.2f\n", receipt[j].receiptLibelle, receipt[j].receiptCode, receipt[j].receiptPrix, receipt[j].minSupp, receipt[j].S); //for resultat
    }

    printf("\n_____________________________________\n");
    printf("          TOTALE:%.2f            \n", ttlcost);
    fprintf(rslt, "TOTALE:%.2f\n", ttlcost); //for resultat
                 
				


    
				 
				                             /* close  files*/
    fclose(idt);
    fclose(rslt);
   fclose(bdt); //    fclose(bdt);
    //   fprintf (bdt,);

    return 0;
}

