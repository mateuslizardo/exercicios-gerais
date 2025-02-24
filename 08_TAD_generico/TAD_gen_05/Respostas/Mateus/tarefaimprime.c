#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefaimprime.h"

struct impr {
    char* msg;
};

tImpr* CriaTarefaImprimir(char *msg){
    tImpr *i = (tImpr*)calloc(1, sizeof(tImpr));
    i->msg = strdup(msg);
    return i;
}

void ExecutaTarefaImprimir(void *imp){
    tImpr *i = (tImpr*) imp;
    printf("\n%s", i->msg);
}

void DestroiTarefaImprimir(void *imp){
    tImpr *i = (tImpr*) imp;
    free(i->msg);
    free(i);
}