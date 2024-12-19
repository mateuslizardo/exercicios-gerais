#include <stdio.h>
#include "product.h"
#include "store.h"

int main(){
    tStore loja = abreLoja();
    int cont = 0;
    while(1){
        imprimeMenu();
        char c;
        scanf("%c\n", &c);
       // printf("%c\n", c);
        
        if(c == 'F'){
            break;
        }

        if(c == 'C'){
            tProduct p = leProduto();
            loja = adicionaProduto(loja, p);
        } else if(c == 'E'){
            int id, qtd;
            printf("Digite o id do Produto: Digite o numero de unidades: ");
            scanf("%d\n%d\n", &id, &qtd);
            loja = aumentaEstoqueLoja(loja, id, qtd);
            printf("\n");
        } else if(c == 'V'){
            int id, qtd;
            printf("Digite o id do Produto: Digite o numero de unidades: ");
            scanf("%d\n%d\n", &id, &qtd);
            loja = vendeProdutoLoja(loja, id, qtd);
            printf("\n");
        } else if(c == 'D'){
            int id;
            float desc;
            printf("Digite o id do Produto: Digite o novo desconto: ");
            scanf("%d\n%f\n", &id, &desc);
            loja = atualizaDescontoLoja(loja, id, desc);
            printf("\n");
        } else if(c == 'I'){
            imprimeProdutosLoja(loja);
            printf("\n");
        } else if(c == 'R'){
            imprimeRelatorio(loja);
            printf("\n");
        }
    }
}

void imprimeMenu(){
    printf("Menu:\n C - Cadastrar Produto\n E - Estocar Produto\n V - Vender Produto\n D - Atualizar desconto de Produto\n I - Imprimir Produtos\n R - Imprimir Relatorio de Vendas\n F - Finalizar Programa\n");
}