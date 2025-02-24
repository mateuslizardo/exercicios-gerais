#include "utils.h"

void LeNumeros(int *array, int tamanho){
    for(int i=0; i<tamanho; i++){
        scanf("%d", &array[i]);
    }
}

void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media){
    *menor = array[0];
    float soma = array[0];
    for(int i=1; i<tamanho; i++){
        if(array[i] < *menor){
            *menor = array[i];
        }
        if(array[i] > *maior){
            *maior = array[i];
        }
        soma += array[i];
    }
    *media = soma/(float)tamanho;
}