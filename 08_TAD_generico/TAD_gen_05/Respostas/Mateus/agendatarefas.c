#include <stdio.h>
#include <stdlib.h>
#include "agendatarefas.h"

typedef struct {
    int prioridade;
    void *tarefa;
    void (*executa)(void*);
    void (*destroi)(void*);
} Tarefa;

struct agendatarefas {
    Tarefa **tarefas;
    int numElem;
    int count;
};

tAgendaTarefas* CriaAgendaDeTarefas(int numElem){
    tAgendaTarefas *a = (tAgendaTarefas*)calloc(1, sizeof(tAgendaTarefas));
    a->numElem = numElem;
    a->count = 0;
    a->tarefas = (Tarefa**) calloc(numElem, sizeof(Tarefa*));
    return a;
}

void DestroiAgendaDeTarefas(tAgendaTarefas* tar){
    for(int i=0; i<tar->numElem; i++){
        tar->tarefas[i]->destroi(tar->tarefas[i]->tarefa);
        free(tar->tarefas[i]);
    }
    free(tar->tarefas);
    free(tar);
}

void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*) ){
    Tarefa *t = (Tarefa*) calloc(1, sizeof(Tarefa));
    t->prioridade = prioridade;
    t->tarefa = tarefa;
    t->executa = executa;
    t->destroi = destroi;
    tar->tarefas[tar->count] = t;
    tar->count++;
}

void ExecutarTarefasDaAgenda(tAgendaTarefas* tar){
    for (int i = 0; i < tar->count - 1; i++) {
        for (int j = 0; j < tar->count - i - 1; j++) {
            if (tar->tarefas[j]->prioridade < tar->tarefas[j + 1]->prioridade) {
                Tarefa *temp = tar->tarefas[j];
                tar->tarefas[j] = tar->tarefas[j + 1];
                tar->tarefas[j + 1] = temp;
            }
        }
    }
    for(int i=0; i<tar->numElem; i++){
        tar->tarefas[i]->executa(tar->tarefas[i]->tarefa);
    }
}