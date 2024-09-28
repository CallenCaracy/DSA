#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "LinearHash.c"

int main(void){
    HashTable ht;
    initDictionary(&ht, 10);
    visualizeTable(ht);
    insert(&ht, createStud(1, "Callen", "BSIT", 2));
    visualizeTable(ht);
    insert(&ht, createStud(2, "Lark", "BSIS", 3));
    visualizeTable(ht);
    insert(&ht, createStud(3, "Caracy", "BSIT", 1));
    visualizeTable(ht);
    insert(&ht, createStud(4, "Lark", "BSIT", 4));
    visualizeTable(ht);
    insert(&ht, createStud(5, "Srvend", "BSIS", 2));
    visualizeTable(ht);
    insert(&ht, createStud(6, "Len", "BSCS", 1));
    visualizeTable(ht);
    delete(&ht, createStud(6, "Len", "BSCS", 1));
    visualizeTable(ht);
    resizeMax(&ht);
    insert(&ht, createStud(5, "Clarence", "BSBSIT", 100));
    visualizeTable(ht);
    clearData(&ht);
    visualizeTable(ht);
    return 0;
}