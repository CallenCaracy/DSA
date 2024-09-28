#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Data.h"

Name createName(char fname[20], char lname[20]) {
    Name n;
    
    strcpy(n.fname, fname);
    strcpy(n.lname, lname);
    
    return n;
}