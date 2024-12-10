#include <stdio.h>
#include "product.h"
#include "store.h"

int main(){
    tStore loja;
    int cont = 0;
    while(1){
        char c = getchar();
        if(c == 'F'){
            break;
        }

        if(c == 'C'){
            loja.nmProdutos++;
            tProduct p = leProduto();
            loja.produtos[loja.nmProdutos] = criaProduto(p.nome, p.desconto, p.preco, p.estoque, p.id);
        }
    }
}