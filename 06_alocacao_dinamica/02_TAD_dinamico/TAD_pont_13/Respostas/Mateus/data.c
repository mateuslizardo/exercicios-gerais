#include <stdio.h>
#include <stdlib.h>
#include "data.h"

tData* LeData(){
    tData* d = (tData*) calloc(1, sizeof(tData));
    scanf("%d/%d/%d\n", &d->dia, &d->mes, &d->ano);
    return d;
}

tData* CriaData(int dia, int mes, int ano){
    tData* d = (tData*) calloc(1, sizeof(tData));
    d->dia = dia;
    d->mes = mes;
    d->ano = ano;
    return d;
}

void LiberaData(tData* d){
    free(d);
}

int CalculaIdadeData(tData* nascimento, tData* diacalc){
    int diff = diacalc->ano - nascimento->ano;

    if(nascimento->mes > diacalc->mes){
        return diff-1;
    } else if(nascimento->mes == diacalc->mes){
        if(nascimento->dia > diacalc->dia){
            return diff-1;
        } else {
            return diff;
        }
    } else {
        return diff;
    }
}

void ImprimeData(tData* d){
    printf("%d/%d/%d\n", d->dia, d->mes, d->ano);
}