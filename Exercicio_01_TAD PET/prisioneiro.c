#include "prisioneiro.h"

tPrisioneiro criaPrisioneiro(char* nome, int pena){
    tPrisioneiro p;
    strcpy(p.nome, nome);
    p.pena = pena;
    p.tempoPassado = 0;
    return p;
}

void passaTempoPrisioneiro(tPrisioneiro* prisioneiro){
    prisioneiro->tempoPassado++;
}

void fogePrisioneiro(tPrisioneiro* prisioneiro){
    printf("Detento %s fugiu!\n", prisioneiro->nome);
}

int acabouPenaPrisioneiro(tPrisioneiro* prisioneiro){
    if( prisioneiro->tempoPassado == prisioneiro->pena){
        return 1;
    } else
        return 0;
}

void liberaPrisioneiroCumpriuPena(tPrisioneiro* prisioneiro){
    printf("Detento %s cumpriu sua pena e foi liberado\n", prisioneiro->nome);
}

void liberaPrisioneiroFimPrograma(tPrisioneiro* prisioneiro){
    printf("Prisioneiros liberados para a finalizacao do programa!!!");
}