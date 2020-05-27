#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char  *code; //pointeur
    char  *libelle;
    float prix;

}typeDuBien;

static typeDuBien biens[] =
{
//    { "00310", "Poulette",  35.00 },
//    { "00311", "porc",  20.50 },
//    { "00322", "Du boeuf",  45.00 },
//    { "00323", "Poisson",  40.00 },
//    { "00510", "T-shirt",  75.00 },
//    { "00511", "Pantalon", 120.00 },
//    { "00512", "Manteau", 100.00 },
//    { "00513", "Sauteuse",  85.00 },
//    { "00710", "Agresser",  15.50 },
//    { "00711", "Poêle à frire", 200.00 },
//    { "00712", "bol",  25.00 },    
    { "1009", "creme_glacee",  3.56 },
    { "167", "fromage",  1.55 },
    { "123", "jus",  1.35 },
    { "500", "lait",  0.97 },
    { "890", "coca",  1.22 },
    { "654", "chocolat",  2.78 },
    { "763", "crevette",  33.62 },
    { "34", "serviette_papier",  0.87 },
};
static int bienstotal = sizeof(biens) / sizeof(biens[0]);
int main( void )

{
	//afficher table
	unsigned int i,j,minSupp;
//	    int S;
    for (i = 0; i < bienstotal; i++ )
        printf( "%s %s %f\n", biens[i].code, biens[i].libelle, biens[i].prix );
    	printf( "\n Nombres totales des biens: %d\n", bienstotal );



char tempCode[6]; //code entrer

typedef struct receipt
{
char receiptLibelle[20], receiptCode[6];
float receiptPrix,S;
int minSupp;
}receipttype;

receipttype receipt[13];
char stop[2] = {"F"}; //sorter du programme
float ttlcost = 0; //resultat final

unsigned int total = 0; //nbr de produit dans le tableaux
    FILE * bdt;	//file bdt
	FILE * idt;	//file identi
	FILE * rslt; //file resultat		


while ( strcmp(tempCode, stop) ){ //strcmp comparer entre 2 string
printf("\n Veuillez saisir le code article. Tapez F pour terminer: ");
scanf("%s", tempCode);
printf("Donner nombre de produits: ");
scanf("%d", &minSupp);

for (i = 0; i < bienstotal; ++i){
	if(strcmp(tempCode, biens[i].code) == 0){
        strcpy(receipt[total].receiptLibelle, biens[i].libelle); //strcpy copy
        strcpy(receipt[total].receiptCode, biens[i].code);
        receipt[total].receiptPrix = biens[i].prix ;
		receipt[total].S = biens[i].prix * minSupp ;
		receipt[total].minSupp = minSupp ;
        ttlcost += biens[i].prix;
        total++;
    }

}

}
printf("_____________________________________\n\n");
printf("      MERCI DE VOTRE VISITE!     \n");
printf("_____________________________________\n");
printf("         Voici votre reçu:       \n\n");
printf("%10s %20s %10s %20s %s", " Libelle ", " Code "," Prix "," Supp", " QTT\n");



//files 
   bdt = fopen ("Bdt.txt","a");  /* Bdt.txt*/ //"a" for contenu typing "w" for deleting and put new ligne
   idt = fopen ("identifiant.txt","a");  /* identifiant.txt*/
   rslt = fopen("resultat.txt","a");

for (j= 0; j < total; ++j){
printf("%10s %10s %10.2f %10.2f %10d\n", receipt[j].receiptLibelle, receipt[j].receiptCode, receipt[j].receiptPrix, receipt[j].S, receipt[j].minSupp);



fprintf(idt,"%10s%10s%10.2f\n", receipt[j].receiptCode, receipt[j].receiptLibelle,  receipt[j].receiptPrix); //for identifiant
fprintf (bdt, "%10s",  receipt[j].receiptCode); //for Bdt
fprintf(rslt,"%10s%10s%10.2f\n", receipt[j].receiptCode, receipt[j].receiptLibelle,  receipt[j].receiptPrix); //for resultat
}
printf("\n_____________________________________\n");
printf("          TOTALE:%.2f            \n", ttlcost);
fprintf(rslt,"TOTALE:%.2f\n", ttlcost); //for resultat
/* close  files*/  
   fclose (idt);
   fclose(rslt);
   fclose(bdt);
//   fprintf (bdt,);
   return 0;
}
