#include <stdio.h>
#include "jogada.h"

tJogada LeJogada(){
    tJogada j;
    printf("Digite uma posicao (x e y):\n");
    scanf("%d %d\n", &j.x, &j.y);

    j.sucesso = 1; //??
    return j;
}

int ObtemJogadaX(tJogada jogada){
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada){
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada){
    return jogada.sucesso;
}