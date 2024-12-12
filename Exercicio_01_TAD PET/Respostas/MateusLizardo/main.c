#include <stdio.h>
#include "product.h"
#include "store.h"

int main(){
    tStore loja = abreLoja();
    int cont = 0;
    while(1){
        imprimeMenu();
        char c = getchar();
        if(c == 'F'){
            break;
        }

        if(c == 'C'){
            tProduct p = leProduto();
            loja = adicionaProduto(loja, p);
        } else if(c == 'E'){
            int id, qtd;
            scanf("%d%d", id, qtd);
            
        }
    }
}

void imprimeMenu(){
    printf("Menu:\nC - Cadastrar Produto\nE - Estocar Produto\nV - Vender Produto\nD - Atualizar desconto de Produto\nI - Imprimir Produtos\nR - Imprimir Relatorio de Vendas\nF - Finalizar Programa\n");
}