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
    char *time1 = (char*)calloc(MAX_TIME_NOME, sizeof(char));
    char *time2 = (char*)calloc(MAX_TIME_NOME, sizeof(char));
    
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
    free(time1);
    free(time2);
    OrdenaTabela(br->tabela);
}

void RealizaCamp(BRA *br) {
    char opcao;
    int quantPartidas = 0;
    while (scanf("%c\n", &opcao) == 1) {
        printf("Menu:\n");
        printf("C - Continuar\n");
        printf("R - Retirar 2 times e seguir\n");
        printf("F - Finalizar\n\n");
                
        
        if (opcao == 'C') {
            for(int i = 0; i < br->numTimes/2; i++)
                RealizaRodada(br);            
            ImprimeTabela(br->tabela);
            quantPartidas++;
        } else if (opcao == 'R') {
            printf("Times a serem retirados:\n");
            RemoveTimesCamp(br);
        }
        
        if (opcao == 'F' || quantPartidas == br->numRodadas) {
            printf("Esta foi a tabela final:\n");
            ImprimeTabela(br->tabela);
            break;
        } 

        if(br->numTimes == 0) {
            break;
        }
        
    }
}

void RemoveTimesCamp(BRA *br) {
    char time1[50], time2[50];
    scanf("%s %s\n", time1, time2);
    RemoveTimeTabela(br->tabela, time1);
    RemoveTimeTabela(br->tabela, time2);
    printf("Os times %s e %s se retiraram do campeonato\n", time1, time2);
    br->saidas += 2;
    br->numTimes -= 2;
    if(br->numTimes > 1){
        RealizaRodada(br);
        ImprimeTabela(br->tabela);
    }
}

void DesalocaCamp(BRA *br) {
    DesalocaTabela(br->tabela);
    free(br);
}

void FinalizaCamp(BRA *br) {
    ImprimePremiacao(br->tabela, br->premio);
    printf("Fim do campeonato\n");
    DesalocaCamp(br);
}