#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "HashTable.c"

int main(void) {
    HashTable ht;
    initDictionary(&ht);
    insert(&ht, createStud(1, "Calen", "BSIT", 2));
    insert(&ht, createStud(2, "Calen", "BSIT", 1));
    insert(&ht, createStud(3, "Larcy", "BSIT", 2));
    insert(&ht, createStud(4, "Len", "BSIT", 2));
    insert(&ht, createStud(5, "Lark", "BSIT", 2));
    insert(&ht, createStud(6, "Caracy", "BSIT", 2));
    visualizeTable(ht);
    delete(&ht, createStud(2, "Calen", "BSIT", 1));
    insert(&ht, createStud(6, "Boulder Holder", "BSIT", 5));
    visualizeTable(ht);

    return 0;
}