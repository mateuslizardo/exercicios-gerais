#include <stdio.h>
#include "product.h"
#include <string.h>

tProduct leProduto() {
    tProduct p;
    printf("Nome do Produto: ID: Preco: Desconto: Estoque:");
    scanf("%[^\n]", p.nome);
    scanf("%d\n", &p.id);
    scanf("%f\n", &p.preco);
    scanf("%f\n", &p.desconto);
    scanf("%d\n", &p.estoque);
    return p;
}

tProduct criaProduto(char* nome, float desconto, float preco, int estoque, int id){
    tProduct p;
    strcpy(p.nome, nome);
    p.desconto = desconto;
    p.preco = preco;
    p.estoque = estoque;
    p.id = id;
    p.vendas = 0;
    return p;
}

float obtemDesconto(tProduct produto){
    return produto.desconto;
}
float obtempreco(tProduct produto){
    return produto.preco;
}

float obtemPrecoComDesconto(tProduct produto){
    float preco = obtempreco(produto);
    float desconto = obtemDesconto(produto);
    desconto = 100.0 - desconto;

    return preco * desconto;
}

int obtemEstoque(tProduct produto){
    return produto.estoque;
}

int obtemVendas(tProduct produto){
    return produto.vendas;
}

int obtemId(tProduct produto){
    return produto.id;
}

tProduct aumentaEstoqueProduto(tProduct produto, int qtd){
    if(qtd > 0){
        produto.estoque += qtd;
    }
    return produto;
}

tProduct vendeProduto(tProduct produto, int qtd){
    if(produto.estoque >= qtd){
        produto.estoque -= qtd;
        produto.vendas++;
    }
    return produto;
}

tProduct atualizaDesconto(tProduct produto, float desconto){
    if(desconto >= 0.0 && desconto <= 1.0){
        produto.desconto = desconto;
    }
    return produto;
}

bool ehMesmoId(tProduct produto, int id){
    if(produto.id == id){
        return true;
    } else return false;
}

void imprimeProduto(tProduct produto){
    printf("Produto: %s, Preco atual: %.2f, Qtd no estoque: %d, Qtd vendida: %d\n", produto.nome, produto.preco, produto.estoque, produto.vendas);
}