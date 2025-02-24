#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

struct generic {
    void *vetor;
    int numElem;
    Type tipo;
};

tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric *g = (tGeneric*) calloc(1, sizeof(tGeneric));
    g->numElem = numElem;
    g->tipo = type;
    switch(g->tipo){
        case INT:
            g->vetor = (int*) calloc(g->numElem, sizeof(int));
            break;

        case FLOAT:
            g->vetor = (float*) calloc(g->numElem, sizeof(float));
            break;
    }

    return g;
}

void DestroiGenerico(tGeneric* gen){
    free(gen->vetor);
    free(gen);
}

void LeGenerico(tGeneric* gen){
    printf("\nDigite o vetor:\n");
    switch(gen->tipo){
        case INT:
            for(int i=0; i < gen->numElem; i++){
                int temp;
                scanf("%d ", &temp);
                ((int*) gen->vetor)[i] = temp;
            }
            break;
        
        case FLOAT:
            for(int i=0; i < gen->numElem; i++){
                float temp;
                scanf("%f ", &temp);
                ((float*) gen->vetor)[i] = temp;
            }
            break;
    }
}

void ImprimeGenerico(tGeneric* gen){
    switch(gen->tipo){
        case INT:
            for(int i=0; i < gen->numElem; i++){
                int temp = ((int*) gen->vetor)[i];
                printf("%d ", temp);
            }
            break;
        
        case FLOAT:
            for(int i=0; i < gen->numElem; i++){
                float temp = ((float*) gen->vetor)[i];
                printf("%.2f ", temp);
            }
            break;
    }
}