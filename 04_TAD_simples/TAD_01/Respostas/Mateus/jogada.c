#include <stdio.h>
#include "jogada.h"
#include "tabuleiro.h"

tJogada LeJogada(){
    tJogada j;
    printf("Digite uma posicao (x e y):\n");
    scanf("%d %d\n", &j.x, &j.y);

    if(EhPosicaoValidaTabuleiro(j.x, j.y)){
        j.sucesso = 1;
    } else {
        j.sucesso = 0;
    }
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