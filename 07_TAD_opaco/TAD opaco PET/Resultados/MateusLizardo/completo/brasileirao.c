#include <stdio.h>
#include <stdlib.h>
#include "brasileirao.h"
#include <string.h>

struct _BRA {
    int numTimes;
    int numRodadas;
    int saidas;
    int premio;
    tTabela *tabela;
};

BRA *CriaCamp() {
    BRA *br = (BRA *)calloc(1,sizeof(BRA));
    if (br == NULL) {
        free(br);
        exit(1);
    }
    printf("Insira o num de times, rodadas e premio total:\n");
    scanf("%d %d %d\n", &br->numTimes, &br->numRodadas, &br->premio);
    br->tabela = CriaTabela(br->numTimes);
    if(br->tabela == NULL) {
        DesalocaTabela(br->tabela);
        exit(1);
    }
    br->saidas = 0;
    return br;
}

void RealizaRodada(BRA *br) {
    int i, j, gols1, gols2;
    char time1[50], time2[50];

    for (i = 0; i < br->numTimes/2; i++) {
        scanf("%s %d x %d %s\n", time1, &gols1, &gols2, time2);
        AtualizaGolsMarcados(ObtemTimeTabela(br->tabela, time1), gols1);
        AtualizaGolsSofridos(ObtemTimeTabela(br->tabela, time1), gols2);
        AtualizaGolsMarcados(ObtemTimeTabela(br->tabela, time2), gols2);
        AtualizaGolsSofridos(ObtemTimeTabela(br->tabela, time2), gols1);
        if (gols1 > gols2) {
            AtualizaVitorias(ObtemTimeTabela(br->tabela, time1));
            AtualizaDerrotas(ObtemTimeTabela(br->tabela, time2));
        } else if (gols1 < gols2) {
            AtualizaVitorias(ObtemTimeTabela(br->tabela, time2));
            AtualizaDerrotas(ObtemTimeTabela(br->tabela, time1));
        } else {
            AtualizaEmpates(ObtemTimeTabela(br->tabela, time1));
            AtualizaEmpates(ObtemTimeTabela(br->tabela, time2));
        }
    }
}

void RealizaCamp(BRA *br) {
    char opcao;
    while (1) {
        printf("Menu:\n");
        printf("C - Continuar\n");
        printf("R - Retirar 2 times e seguir\n");
        printf("F - Finalizar\n\n");
                
        scanf("%c\n", &opcao);
        if (opcao == 'C') {
            RealizaRodada(br);
            OrdenaTabela(br->tabela);
            ImprimeTabela(br->tabela);
        } else if (opcao == 'R') {
            RemoveTimesCamp(br);
            OrdenaTabela(br->tabela);
            ImprimeTabela(br->tabela);
        } else if (opcao == 'F') {
            OrdenaTabela(br->tabela);
            FinalizaCamp(br);
            break;
        } 

        if(br->saidas == br->numTimes) {
            OrdenaTabela(br->tabela);
            FinalizaCamp(br);
            break;
        }
        
    }
}

void RemoveTimesCamp(BRA *br) {
    char time1[50], time2[50];
    scanf("%s %s\n", time1, time2);
    RemoveTimeTabela(br->tabela, time1);
    RemoveTimeTabela(br->tabela, time2);
    br->saidas += 2;
}

void DesalocaCamp(BRA *br) {
    DesalocaTabela(br->tabela);
    free(br);
}

void FinalizaCamp(BRA *br) {
    ImprimeTabela(br->tabela);
    ImprimePremiacao(br->tabela, br->premio);
    DesalocaCamp(br);
}