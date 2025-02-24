#include <stdio.h>
#include "jogador.h"
#include "jogada.h"
#include "tabuleiro.h"

tJogador CriaJogador(int idJogador){
    tJogador j;
    j.id = idJogador;
    return j;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){
    tJogada jogada;
    jogada = LeJogada();

    if(FoiJogadaBemSucedida(jogada)==1 && EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada))){
        tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
        return tabuleiro;
    }
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){
    
}