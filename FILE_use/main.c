#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char prodName[20];
    float prodPrice;
}Product;

Product newProduct(char *product, float price);
void displayProduct(Product p);

int main(void) {
    FILE *fp;
    Product prod;

    fp = fopen("my_product.file", "rb");

    if(fp != NULL){
        while(fread(&prod, sizeof(Product), 1, fp)){
            displayProduct(prod);
            printf("\n");
        }
    }

    fclose(fp);

    return 0;
}

Product newProduct(char *product, float price){
    Product p;

    strcpy(p.prodName, product);
    p.prodPrice = price;

    return p;
}

void displayProduct(Product p){
    printf("%15s - Php %.2f", p.prodName, p.prodPrice);
}