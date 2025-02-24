#include "vetor.h"

void LeDadosParaVetor(int * vet, int tam){
    for(int i=0; i<tam; i++){
        scanf("%d", &vet[i]);
    }
}

void ImprimeDadosDoVetor(int * n, int tam){
    for(int i=0; i<tam; i++){
        printf("%d ", n[i]);
    }
    printf("\n");
}

void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar){
    if(vet[*paraTrocar] > vet[*paraTrocar+1]){
        int temp = vet[*paraTrocar];
        vet[*paraTrocar] = vet[*paraTrocar+1];
        vet[*paraTrocar+1] = temp;
    }
}

void OrdeneCrescente(int * vet, int tam){
    for(int i=0; i<tam - 1; i++){
        for(int j=0; j <tam - 1 - i; j++){
            TrocaSeAcharMenor(vet, tam, &j);
        }
    }
}