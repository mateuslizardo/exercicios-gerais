#include "utils.h"

void LeIntervalo(int * m, int * n){
    scanf("%d %d\n", m, n);
}

int EhPrimo(int n){
    int cont = 0;
    for(int i=1; i<=n; i++){
        if(n % i == 0){
            cont++;
        }
        if(cont==3){
            return 0;
        }
    }
    return 1;
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior){
    *menor = n;
    *maior = m;
    for(int i=m; i<=n; i++){
        if(EhPrimo(i)){
            if(i < *menor){
                *menor = i;
            }
            if(i > *maior){
                *maior = i;
            }
        }
    }
}