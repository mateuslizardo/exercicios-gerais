#include "cela.h"

tCela criaCela(int capacidade){
    tCela c;
    c.capacidade = capacidade;
    c.nPresidiarios = 0;
    return c;
}

int possuiVagaCela(tCela* cela){
    return cela->capacidade > cela->nPresidiarios ? 1 : 0;
}

int obtemNumeroPrisioneirosCela(tCela* cela){
    return cela->nPresidiarios;
}

void inserePrisioneiroCela(tCela* cela, tPrisioneiro prisioneiro){
    if(possuiVagaCela(cela)){
        cela->prisioneiros[cela->nPresidiarios] = prisioneiro;
        cela->nPresidiarios++;
    }
}