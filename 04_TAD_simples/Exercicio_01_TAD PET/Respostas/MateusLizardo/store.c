#include <stdio.h>
#include "store.h"

tStore abreLoja(){
    tStore loja;
    loja.faturamento = 0.0;
    loja.nmProdutos = 0;
    loja.nmVendas = 0;
    return loja;
}

tStore adicionaProduto(tStore loja, tProduct produto){
    loja.produtos[loja.nmProdutos] = criaProduto(produto.nome, produto.desconto, produto.preco, produto.estoque, produto.id);
    loja.nmProdutos++;
    return loja;
}

int buscaProduto(tStore loja, int id){
    for(int i=0; i<loja.nmProdutos; i++){
        if(ehMesmoId(loja.produtos[i], id)){
            return i;
        }
    }
    return -1;
}

tStore aumentaEstoqueLoja(tStore loja, int id, int qtd){
    loja.produtos[buscaProduto(loja, id)] = aumentaEstoqueProduto(loja.produtos[buscaProduto(loja, id)], qtd);
    return loja;
}

tStore vendeProdutoLoja(tStore loja, int id, int qtd){
    loja.produtos[buscaProduto(loja, id)] = vendeProduto(loja.produtos[buscaProduto(loja, id)], qtd);
    loja.nmVendas += qtd;
    float preco = obtemPrecoComDesconto(loja.produtos[buscaProduto(loja, id)]);
    loja.faturamento += (float) (preco * qtd);
    return loja;
}

tStore atualizaDescontoLoja(tStore loja, int id, float desconto){
    loja.produtos[buscaProduto(loja, id)] = atualizaDesconto(loja.produtos[buscaProduto(loja, id)], desconto);
    return loja;
}

void imprimeProdutosLoja(tStore loja){
    for(int i=0; i<loja.nmProdutos; i++){
        imprimeProduto(loja.produtos[i]);
    }
}

void imprimeRelatorio(tStore loja){
    printf("RELATORIO DE VENDAS ATUALIZADO:\n");
    printf("TOTAL DE VENDAS: %d\n", loja.nmVendas);
    printf("FATURAMENTO: %.2f\n", loja.faturamento);
    printf("PRODUTOS EM ESTOQUE: %d\n", obtemEstoqueLoja(loja));
    printf("PRODUTO MAIS VENDIDO:\n");
    imprimeMaisVendido(loja);
}

int obtemEstoqueLoja(tStore loja){
    int estoque = 0;
    for(int i=0; i<loja.nmProdutos; i++){
        estoque += loja.produtos[i].estoque;
    }
    return estoque;
}

void imprimeMaisVendido(tStore loja){
    tProduct melhor = loja.produtos[0];
    for(int i=1; i<loja.nmProdutos; i++){
        if(loja.produtos[i].vendas > melhor.vendas){
            melhor = loja.produtos[i];
        }
    }
    imprimeProduto(melhor);
}