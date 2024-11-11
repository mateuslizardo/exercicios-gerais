#include "matrix_utils.h"
#include <stdio.h>
#include <stdlib.h>

int opcoes(int opt){
    printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida: \n");
    scanf("%d", &opt);
    return opt;
}

int main() {
    int linhas1, colunas1, linhas2, colunas2, opt;
    scanf("%d %d", &linhas1, &colunas1);
    int matriz1[linhas1][colunas1], res[linhas1][colunas1];
    matrix_read(linhas1, colunas1, matriz1);
    scanf("%d %d", &linhas2, &colunas2);
    int matriz2[linhas2][colunas2];
    matrix_read(linhas2, colunas2, matriz2);

    while(1){
        opt = opcoes(opt);
        switch(opt){
            case 1:
                if(possible_matrix_sum(linhas1, colunas1, linhas2, colunas2)) {
                    matrix_add(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2, res);
                    matrix_print(linhas1, colunas1, res);
                } else printf("Erro: as dimensoes da matriz nao correspondem\n\n");
                break;
            
            case 2:
                if(possible_matrix_sub(linhas1, colunas1, linhas2, colunas2)) {
                    matrix_sub(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2, res);
                    matrix_print(linhas1, colunas1, res);
                } else printf("Erro: as dimensoes da matriz nao correspondem\n\n");
                break;

            case 3:
                if(possible_matrix_multiply(colunas1, linhas2)) {
                    matrix_multiply(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2, res);
                    matrix_print(linhas1, colunas2, res);
                } else printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
                break;
            
            case 4:
                int numat, escalar;
                scanf("%d %d", &escalar, &numat);
                if(numat==1) {
                    scalar_multiply(linhas1, colunas1, matriz1, escalar);
                    matrix_print(linhas1, colunas1, matriz1);
                }
                else {
                    scalar_multiply(linhas2, colunas2, matriz2, escalar);
                    matrix_print(linhas2, colunas2, matriz2);
                }
                break;

            case 5:
                transpose_matrix(linhas1, colunas1, matriz1, res);
                matrix_print(colunas1, linhas1, res);
                transpose_matrix(linhas2, colunas2, matriz2, res);
                matrix_print(colunas2, linhas2, res);
                break;

            case 6:
                exit(1);
        }
        }
}