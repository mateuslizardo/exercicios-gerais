#include "utils.h"

int TrocaInterios(int * n1, int * n2){
    if(*n1 <= *n2)
        return 0;

    else {
        int prov = *n1;
        *n1 = *n2;
        *n2 = prov;
        return 1;
    }
}