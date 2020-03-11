#include <stdio.h>

#define salesMen 4
#define products 5

void calculateSales(int sales[][products], int prices[], int sp[]);
void calculateProductSales(int sales[][products], int productSale[]);
void maxArray(int array[], int size, int *max, int *pos);
void printArray(int array[], int size);

int main() {

    int prices[] = {250, 150, 320, 210, 920};
    int sales[salesMen][products]  = { {10,  4,  5, 6, 7},
                                       { 7,  0, 12, 1, 3},
                                       { 4, 19,  5, 0, 8},
                                       { 3,  2,  1, 5, 6} };

    int salesPerson[salesMen];
    calculateSales(sales,prices,salesPerson);

    printf("SalesMan-Sales\n");
    printArray(salesPerson,salesMen);

    int bestManSales, bestManPos;
    maxArray(salesPerson,salesMen, &bestManSales, &bestManPos);
    printf("Best SalesMan was %d with %d sales\n", bestManPos, bestManSales);

    int productSale[products];
    calculateProductSales(sales,productSale);

    printf("Product-Items\n");
    printArray(productSale,products);

    int bestProductSales, bestProductPos;
    maxArray(productSale,products, &bestProductSales, &bestProductPos);
    printf("Best Product was %d with %d items", bestProductPos, bestProductSales);

return 0;
}

void calculateSales(int sales[][products], int prices[], int sp[]) {
    for (int i=0; i<salesMen;i++){
        sp[i]=0;
        for(int j=0; j<products; j++){
            sp[i]+=sales[i][j]*prices[j];
        }
    }
}

void printArray(int array[], int size);
void calculateProductSales(int sales[][products], int productSale[]){
    for (int j=0; j<products; j++){
        productSale[j]=0;
        for (int i=0; i<salesMen; i++){
            productSale[j]+=sales[i][j];
        }
    }
}

void maxArray(int array[], int size, int *max, int *pos) {
    *max = -1;
    *pos= -1;
    for (int i=0;i<size;i++) {
        if (array[i]> *max) {
            *max = array[i];
            *pos = i;
        }
    }
}

void printArray(int array[], int size) {
    for (int i=0; i<size; i++) printf("   %d    %d\n",i,array[i]);
}

