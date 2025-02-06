#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"

char* GetCartaoSusPaciente(tPaciente* p){
    return p->cartaoSus;
}

int GetQtdLesoesPaciente(tPaciente* p){
    return p->qtdLesoes;
}

int GetQtdCirurgiasPaciente(tPaciente* p){
    int cont=0;
    for(int i=0; i < GetQtdLesoesPaciente(p); i++){
        if(PrecisaCirurgiaLesao(p->listaLesao[i])){
            cont++;
        }
    }
    return cont;
}

tData* GetNascimentoPaciente(tPaciente* p){
    return p->nascimento;
}

tPaciente* CriaPaciente(){
    tPaciente* p = (tPaciente*) calloc(1, sizeof(tPaciente));
    p->cartaoSus = (char*) calloc(TAM_CSUS, sizeof(char));
    p->nascimento = (tData*) calloc(1, sizeof(tData));
    p->nome = (char*) calloc(TAM_NOME, sizeof(char));
    p->listaLesao = (tLesao**) calloc(QTD_LESAO, sizeof(tLesao*));
}