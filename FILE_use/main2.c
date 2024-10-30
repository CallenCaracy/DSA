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
    Product list[5];

    list[0] = newProduct("Binangkal", 15);
    list[1] = newProduct("Balbacua", 34.6);
    list[2] = newProduct("Champorado", 23.5);
    list[3] = newProduct("Menudo", 25);

    FILE *fp;

    fp = fopen("my_product.file", "wb");

    if(fp != NULL){
        fwrite(list, sizeof(Product), 4, fp);
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