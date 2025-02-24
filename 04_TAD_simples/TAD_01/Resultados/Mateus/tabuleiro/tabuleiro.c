#include <stdio.h>
#include "tabuleiro.h"

tTabuleiro CriaTabuleiro(){
    tTabuleiro t;
    t.peca1 = 'X';
    t.peca2 = '0';
    t.pecaVazio = '-';

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            t.posicoes[i][j] = t.pecaVazio;
        }
    }
    return t;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
    if(peca==PECA_1)
        tabuleiro.posicoes[y][x] = tabuleiro.peca1;
    else
        tabuleiro.posicoes[y][x] = tabuleiro.peca2;

    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(tabuleiro.posicoes[i][j]==tabuleiro.pecaVazio){
                return 1;
            }
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca){
    if(peca==PECA_1){
        if(tabuleiro.peca1==tabuleiro.posicoes[y][x]){
            return 1;
        } else {
            return 0;
        }
    } else {
        if(tabuleiro.peca2==tabuleiro.posicoes[y][x]){
            return 1;
        } else {
            return 0;
        }
    }
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){
    if(tabuleiro.posicoes[y][x]==tabuleiro.pecaVazio){
        return 1;
    } else {
        return 0;
    }
}

int EhPosicaoValidaTabuleiro(int x, int y){
    if(x>=0 && x<3 && y >=0 && y<3){
        return 1;
    } else {
        return 0;
    }
}

void ImprimeTabuleiro(tTabuleiro tabuleiro){
    for(int i=0; i<3;i++){
        printf("	");
        for(int j=0; j<3;j++){
            printf("%c", tabuleiro.posicoes[i][j]);
        }
        printf("\n");
    }
}