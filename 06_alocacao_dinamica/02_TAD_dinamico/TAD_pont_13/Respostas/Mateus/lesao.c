#include <stdio.h>
#include <stdlib.h>
#include "lesao.h"

tLesao* CriaLesao(){
    tLesao* l = (tLesao*) calloc(1, sizeof(tLesao));
    l->id = (tLesao*) calloc(TAM_ID, sizeof(char));
    l->diagnostico = (tLesao*) calloc(TAM_DIAG, sizeof(char));
    l->regiao_corpo = (tLesao*) calloc(TAM_REG, sizeof(char));
    return l;
}

void LeLesao(tLesao* l){
    scanf("%[^\n]\n", l->id);
    scanf("%[^\n]\n", l->diagnostico);
    scanf("%[^\n]\n", l->regiao_corpo);
    scanf("%d\n", &l->chance_malignidade);
}

void LiberaLesao(tLesao* l){
    free(l->id);
    free(l->diagnostico);
    free(l->regiao_corpo);
    free(l);
}

char* GetIdLesao(tLesao* l){
    return l->id;
}

int PrecisaCirurgiaLesao(tLesao* l){
    return (l->chance_malignidade > 50) ? 1 : 0;
}