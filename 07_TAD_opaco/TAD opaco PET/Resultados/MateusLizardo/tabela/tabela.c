#include "tabela.h"

struct _Tabela {
    tTime** times;
    int numTimes;
    int alocs;
};

tTabela* CriaTabela(int numTimes) {
    tTabela* tabela = (tTabela*) calloc(1,sizeof(tTabela));
    tabela->times = (tTime**) calloc(numTimes, sizeof(tTime*));
    tabela->alocs = 0;
    tabela->numTimes = numTimes;
    for(int i = 0; i < tabela->numTimes; i++) {
        tabela->times[i] = LeTime();
        if(tabela->times[i]!=NULL){
            tabela->alocs++;
        }
        
    }
    
    return tabela;
}

void DesalocaTabela(tTabela* tabela) {
    for (int i = 0; i < tabela->alocs; i++) {
        DesalocaTime(tabela->times[i]);
    }
    free(tabela->times);
    free(tabela);
}

void OrdenaTabela(tTabela* tabela) {
    tTime *troca;
    for (int i = 0; i < tabela->numTimes - 1; i++)
    {
        for (int j = 0; j < tabela->numTimes - 1 - i; j++)
        if (DesempataTimes(tabela->times[j], tabela->times[j + 1]) == 1)
        {
            troca = tabela->times[j];
            tabela->times[j] = tabela->times[j + 1];
            tabela->times[j + 1] = troca;
        }
    }
}

tTime* ObtemTimeTabela(tTabela* tabela, char* time) {
    for (int i = 0; i < tabela->numTimes; i++) {
        if (strcmp(ObtemNomeTime(tabela->times[i]), time) == 0) {
            return tabela->times[i];
        }
    }
    return NULL;
}

void RemoveTimeTabela(tTabela* tabela, char* time) {
    tTime *troca;
    for (int i = 0; i < tabela->numTimes; i++) {
        if (strcmp(ObtemNomeTime(tabela->times[i]), time) == 0) {
            troca = tabela->times[i];
            tabela->times[i] = tabela->times[tabela->numTimes - 1];
            tabela->times[tabela->numTimes - 1] = troca;
            tabela->numTimes--;
            break;
        }
    }
}

void ImprimePremiacao(tTabela* tabela, float valorPremio) {
    if(tabela->numTimes <= 1) {
        printf("Premio de R$%.2f acumulado para a proxima edicao\n", valorPremio);
    } else if(tabela->numTimes == 2) {
        printf("1º lugar - %s: R$%.2f\n", ObtemNomeTime(tabela->times[0]), (valorPremio*60.0)/100.0);
        printf("2º lugar - %s: R$%.2f\n", ObtemNomeTime(tabela->times[1]), (valorPremio*40.0) / 100.0);
    } else {
        printf("1º lugar - %s: R$%.2f\n", ObtemNomeTime(tabela->times[0]), (valorPremio*50.0)/100.0);
        printf("2º lugar - %s: R$%.2f\n", ObtemNomeTime(tabela->times[1]), (valorPremio*30.0) / 100.0);
        printf("3º lugar - %s: R$%.2f\n", ObtemNomeTime(tabela->times[2]), (valorPremio*20.0) / 100.0);
    }
}

void ImprimeTabela(tTabela* tabela) {
    printf("Classificação:\n");
    printf("Nome | Pontos | Vitorias | Derrotas | Empates | Saldo\n");
    for (int i = 0; i < tabela->numTimes; i++) {
        ImprimeTime(tabela->times[i]);
    }
}