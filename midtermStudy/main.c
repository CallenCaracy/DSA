#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stackList.c"

int main(void){
    Stack s;
    ArrayList l;
    iniStack(&s);
    initList(&l, 10);

    addPerson(&l, createPerson("Clarence", "Ayuban", "Diangco", "Bohol"));
    addPerson(&l, createPerson("Caracy", "Hace", "Enzii", "Ubay"));
    addPerson(&l, createPerson("Callen", "Ari", "Srven", "Pitogo"));
    addPerson(&l, createPerson("Larcy", "Leit", "Vertilli", "Cebu"));
    addPerson(&l, createPerson("Ivan", "Dont", "Kyer", "Cebu"));
    addPerson(&l, createPerson("You", "See", "C-Values", "London"));
    visualizeArray(l);

    getVoters(&s, &l, "Cebu");
    getVoters(&s, &l, "London");
    visualizeStack(s);
    return 0;
}