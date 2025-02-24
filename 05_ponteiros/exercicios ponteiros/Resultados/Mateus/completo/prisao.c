#include "prisao.h"

tPrisao criaPrisao(char* nome, int nCelas, int capacidadeCelas){
    tPrisao p;
    strcpy(p.nome, nome);
    p.nCelas = nCelas;
    p.capacidadeCelas = capacidadeCelas;
    p.dia = 0;

    for(int i=0; i<nCelas; i++){
        p.celas[i] = criaCela(capacidadeCelas);
    }

    return p;
}

void executaPrisao(tPrisao* prisao){
    char acabou = 0;
    while(!acabou){
        imprimeDiaEMenuPrisao(prisao);
        char c;
        scanf("%c\n", &c);
        switch (c)
        {
        case 'I':
            inserePrisioneiroPrisao(prisao);
            if(obtemNumeroPrisioneirosPrisao(prisao)==prisao->nCelas * prisao->capacidadeCelas){
                rebeliaoGeralPrisao(prisao);
                acabou = 1;
            }
            break;
        
        case 'P':
            passaDiaPrisao(prisao);
            break;

        case 'F':
            registraFugaCelaPrisao(prisao);
            break;

        case 'E':
            finalizaPrograma(prisao);
            acabou = 1;
            break;
        }
    }
}

void imprimeDiaEMenuPrisao(tPrisao* prisao){
    printf("Dia %d na prisao de %s\n", prisao->dia, prisao->nome);
    printf("Menu:\n");
    printf(" I - Inserir detento\n");
    printf(" P - Passar o dia\n");
    printf(" F - Registrar fuga de cela\n");
    printf(" E - Encerrar programa\n");
}

void inserePrisioneiroPrisao(tPrisao* prisao){
    char nome[MAXTAM_NOME];
    int pena;
    printf("Informe a pena e o nome do prisioneiro:\n");
    scanf("%d %[^\n]\n", &pena, nome);
    if(pena <= 0){
        printf("Valor invalido\n");
        return;
    }

    tPrisioneiro p = criaPrisioneiro(nome, pena);
    
    for(int i=0; i<prisao->nCelas; i++){
        if(possuiVagaCela(&prisao->celas[i])){
            inserePrisioneiroCela(&prisao->celas[i],p);
            printf("Detento %s foi inserido na cela %d\n",nome,i);
            break;
        }
    }
}

void passaDiaPrisao(tPrisao* prisao){
    prisao->dia++;
    for(int i=0; i < prisao->nCelas; i++){
        passaDiaCela(&prisao->celas[i]);
    }
}

void registraFugaCelaPrisao(tPrisao* prisao){
    int i;
    printf("Informe a cela em qual ocorreu a fuga:\n");
    scanf("%d\n", &i);
    
    if(i < 0 || i >= prisao->nCelas){
        printf("Valor invalido\n");
        return;
    }
    fogePrisioneirosCela(&prisao->celas[i]);
}

void finalizaPrograma(tPrisao* prisao){
    if(obtemNumeroPrisioneirosPrisao(prisao)>0){
        printf("Prisioneiros liberados para a finalizacao do programa!!!\n");
    } else {
        printf("Finalizou o programa.\n");
    }
}

int obtemNumeroPrisioneirosPrisao(tPrisao* prisao){
    int cont = 0;
    for(int i=0; i < prisao->nCelas; i++){
        cont += obtemNumeroPrisioneirosCela(&prisao->celas[i]);
    }
    return cont;
}

void rebeliaoGeralPrisao(tPrisao* prisao){
    printf("REBELIAO GERAL\n");
    for(int i=0; i<prisao->nCelas; i++){
        fogePrisioneirosCela(&prisao->celas[i]);
    }
    printf("Fim do programa.\n");
}