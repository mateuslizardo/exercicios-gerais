#include "time.h"

struct _Time {
    char nome[MAX_TIME_NOME];
    int vitorias;
    int empates;
    int derrotas;
    int gols_marcados;
    int gols_sofridos;
};

tTime* LeTime() {
    tTime *t = (tTime*) calloc(1,sizeof(tTime));
    if (t == NULL) {
        return NULL;
    }

    scanf("%[^\n]\n", t->nome);
    t->vitorias = 0;
    t->empates = 0;
    t->derrotas = 0;
    t->gols_marcados = 0;
    t->gols_sofridos = 0;
    return t;
}

int ObtemVitorias(tTime *t) {
    return t->vitorias;
}

int ObtemPartidas(tTime *t) {
    return t->vitorias + t->empates + t->derrotas;
}

int ObtemDerrotas(tTime *t) {
    return t->derrotas;
}

char* ObtemNomeTime(tTime *t) {
    return t->nome;
}

int ObtemSaldo(tTime *t) {
    return t->gols_marcados - t->gols_sofridos;
}

void AtualizaVitorias(tTime *t) {
    t->vitorias++;
}

void AtualizaEmpates(tTime *t) {
    t->empates++;
}

void AtualizaDerrotas(tTime *t) {
    t->derrotas++;
}  

void AtualizaGolsMarcados(tTime *t, int gols) {
    t->gols_marcados += gols;
}

void AtualizaGolsSofridos(tTime *t, int gols) {
    t->gols_sofridos += gols;
}

int ObtemPontos(tTime* t) {
    return t->vitorias * 3 + t->empates;
}

int DesempataTimes(tTime *t1, tTime *t2){
    if (ObtemPontos(t1) > ObtemPontos(t2)) {
        return -1;
    } else if (ObtemPontos(t1) < ObtemPontos(t2)) {
        return 1;
    } else {
        if (ObtemVitorias(t1) > ObtemVitorias(t2)) {
            return -1;
        } else if (ObtemVitorias(t1) < ObtemVitorias(t2)) {
            return 1;
        } else {
            if (ObtemSaldo(t1) > ObtemSaldo(t2)) {
                return -1;
            } else if (ObtemSaldo(t1) < ObtemSaldo(t2)) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}

/**
 * @brief Imprime os dados do time na ordem: Nome | Pontos | Vitorias | Derrotas | Empates | Saldo.
 * Dica: Use a seguinte formatacao no printf: "%-12s | %02d | %02d | %02d | %02d | %+03d\n".
*/
void ImprimeTime(tTime *t){
    printf("%-12s | %02d | %02d | %02d | %02d | %+03d\n", t->nome, ObtemPontos(t), ObtemVitorias(t), ObtemDerrotas(t), t->empates, ObtemSaldo(t));
}

void DesalocaTime(tTime *t){
    free(t);
}