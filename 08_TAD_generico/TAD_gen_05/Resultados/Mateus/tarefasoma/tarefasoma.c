#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefasoma.h"

struct soma {
    float n1;
    float n2;
};

tSoma* CriaTarefaSoma(float n1, float n2){
    tSoma *s = (tSoma*)calloc(1, sizeof(tSoma));
    s->n1 = n1;
    s->n2 = n2;
    return s;
}

void ExecutaTarefaSoma(void *sum){
    tSoma *s = (tSoma*) sum;
    printf("\nO resultado da soma de %.2f com %.2f eh: %.2f", s->n1, s->n2, s->n1+s->n2);
}

void DestroiTarefaSoma(void *sum){
    tSoma *s = (tSoma*) sum;
    free(s);
}