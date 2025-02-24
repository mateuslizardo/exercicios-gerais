#include <stdio.h>
#include <stdlib.h>
#include "tarefamultiplica.h"

struct mult {
    float n1;
    float n2;
};

tMult* CriaTarefaMultiplicar(float n1, float n2){
    tMult *m = (tMult*) calloc(1, sizeof(tMult));
    m->n1 = n1;
    m->n2 = n2;
    return m;
}

void ExecutaTarefaMultiplicar(void *mult){
    tMult *m = (tMult*) mult;
    printf("\nO resultado da multiplicacao de %.2f com %.2f eh: %.2f", m->n1, m->n2, m->n1*m->n2);
}

void DestroiTarefaMultiplicar(void *mult){
    tMult *m = (tMult*) mult;
    free(m);
}