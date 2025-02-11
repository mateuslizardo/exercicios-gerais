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
    p->qtdLesoes = 0;
    p->maxLesoes = QTD_LESAO;
    
    p->cartaoSus = (char*) calloc(TAM_CSUS, sizeof(char));
    p->nome = (char*) calloc(TAM_NOME, sizeof(char));
    p->listaLesao = (tLesao**) calloc(QTD_LESAO, sizeof(tLesao*));

    return p;
}

void LePaciente(tPaciente* p){
    scanf("%[^\n]\n", p->nome);
    p->nascimento = LeData();
    scanf("%[^\n]\n", p->cartaoSus);
    scanf("%c\n", &p->genero);
}

void ImprimePaciente(tPaciente* p){
    if(p->qtdLesoes > 0)
   {     printf("- %s - ", p->nome);
        for(int i=0; i < p->qtdLesoes; i++){
            printf("%s ", p->listaLesao[i]->id);
        }
        printf("\n");}
}

void LiberaPaciente(tPaciente* p){
    free(p->cartaoSus);
    free(p->nome);
    LiberaData(p->nascimento);
    for(int i=0; i < p->qtdLesoes; i++){
        LiberaLesao(p->listaLesao[i]);
    }
    free(p->listaLesao);
    free(p);
}

void AdicionaLesaoPaciente(tPaciente* p, tLesao* l){
    p->listaLesao[p->qtdLesoes] = l;
    p->qtdLesoes++;
}