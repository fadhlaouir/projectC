#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
typedef struct goods
{
char goods_code[6];
char goods_descrip[20];
float price;
}goodtype;

goodtype goods[13];
strcpy(goods[0].goods_descrip, "Chicken");
strcpy(goods[0].goods_code, "00310");
goods[0].price = 35.00;

strcpy(goods[1].goods_descrip, "Pork");
strcpy(goods[1].goods_code, "00311");
goods[1].price = 20.50;

strcpy(goods[2].goods_descrip, "Beef");
strcpy(goods[2].goods_code, "00322");
goods[2].price = 45.00;

strcpy(goods[3].goods_descrip, "Fish");
strcpy(goods[3].goods_code, "00323");
goods[3].price = 40.00;

strcpy(goods[4].goods_descrip, "Walmart T Shirt");
strcpy(goods[4].goods_code, "00510");
goods[4].price = 75.00;

strcpy(goods[5].goods_descrip, "Walmart Trousers");
strcpy(goods[5].goods_code, "00511");
goods[5].price = 120.00;

strcpy(goods[6].goods_descrip, "Walmart Coat");
strcpy(goods[6].goods_code, "00512");
goods[6].price = 100.00;

strcpy(goods[7].goods_descrip, "Walmart Jumper");
strcpy(goods[7].goods_code, "00513");
goods[7].price = 85.00;

strcpy(goods[8].goods_descrip, "Mug");
strcpy(goods[8].goods_code, "00710");
goods[8].price = 15.50;

strcpy(goods[9].goods_descrip, "Fry Pan");
strcpy(goods[9].goods_code, "00711");
goods[9].price = 200.00;

strcpy(goods[10].goods_descrip, "Bowl");
strcpy(goods[10].goods_code, "00712");
goods[10].price = 25.00;

strcpy(goods[11].goods_descrip, "Dish");
strcpy(goods[11].goods_code, "00713");
goods[11].price = 25.00;

char tempCode[6];
typedef struct receipt
{
char receiptNM[20], receiptCD[6];
float receiptPC;
}receipttype;
receipttype receipt[13];
char stop[2] = {"F"};
float ttlcost = 0;
int i,j;
unsigned int count = 0;



while ( strcmp(tempCode, stop) ){
printf("Please enter the item code. Type F to finish: ");
scanf("%s", tempCode);
for (i = 0; i < 12; ++i){
    if (strcmp(tempCode, goods[i].goods_code) == 0){
        strcpy(receipt[count].receiptNM, goods[i].goods_descrip);
        strcpy(receipt[count].receiptCD, goods[i].goods_code);
        receipt[count].receiptPC = goods[i].price;
        ttlcost += goods[i].price;
        count++;
    }

}

}
printf("_____________________________________\n\n");
printf("      THANK YOU FOR VISITING US!     \n");
printf("_____________________________________\n");
printf("         Here is your receipt:       \n\n");
printf("%10s%20s%10s", "Item", "Code", "Price\n");
for (j= 0; j < count; ++j){
printf("%10s%20s%10.2f\n", receipt[j].receiptNM, receipt[j].receiptCD, receipt[j].receiptPC);
}
printf("\n_____________________________________\n");
printf("          TOTAL COST:%.2f            \n", ttlcost);
}
