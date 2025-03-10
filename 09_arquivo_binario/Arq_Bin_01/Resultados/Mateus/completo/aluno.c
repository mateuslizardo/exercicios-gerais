#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

#define MAX_TAM 100

struct aluno {
    char nome[MAX_TAM], data[MAX_TAM], curso[MAX_TAM], periodo[MAX_TAM];
    int percConclusao;
    float coef;
};

Aluno** CriaVetorAlunos(int numeroAlunos){
    Aluno **a = (Aluno**) calloc(numeroAlunos, sizeof(Aluno*));
    return a;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA){
    Aluno *a = (Aluno*) calloc(1, sizeof(Aluno));
    strcpy(a->nome, nome);
    strcpy(a->data, dtNasc);
    strcpy(a->curso, cursoUfes);
    strcpy(a->periodo, periodoIngresso);
    a->percConclusao = percConclusao;
    a->coef = CRA;

    return a;
}   

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos){
    char nome[MAX_TAM], dtNasc[MAX_TAM], cursoUfes[MAX_TAM], periodoIngresso[MAX_TAM];
    int percConclusao;
    float CRA;
    
    for(int i=0; i < numeroAlunos; i++){
        scanf("%[^\n]\n", nome);
        scanf("%[^\n]\n", dtNasc);
        scanf("%[^\n]\n", cursoUfes);
        scanf("%[^\n]\n", periodoIngresso);
        scanf("%d\n", &percConclusao);
        scanf("%f\n", &CRA);
        
        vetorAlunos[i] = CriaAluno(nome, dtNasc, cursoUfes, periodoIngresso, percConclusao, CRA);
    }
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos){
    for(int i=0; i < numeroAlunos; i++){
        free(alunos[i]);
    }
    free(alunos);
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos){
    FILE *f = fopen(fileName, "wb");
    if(f==NULL) exit(1);
    int numBytes = 0;
    for(int i=0; i<numeroAlunos; i++){
        numBytes += sizeof(Aluno) * fwrite(alunos[i], sizeof(Aluno), 1, f);
    }
    fclose(f);
    printf("Numero de bytes salvos: %d\n", numBytes);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName){
    FILE *f = fopen(fileName, "rb");
    int i=0;
    alunos[0] = (Aluno*) calloc(1, sizeof(Aluno));
    while(fread(alunos[i], sizeof(Aluno), 1, f) == 1) {
        i++;
        alunos[i] = (Aluno*) calloc(1, sizeof(Aluno));
    }
    free(alunos[i]);
       
    fclose(f);
}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos){
    for(int i=0; i < numeroAlunos; i++){
        /*
        Aluno 0:
        Nome: Seraphina Luminara
        Data Nascimento: 12 de julho de 2995
        Curso: Engenharia Quantica
        Periodo Ingresso: 2023/1
        % Conclusao do Curso: 85
        CRA: 8.70
        */
       printf("Aluno %d:\n", i);
       printf("Nome: %s\n", alunos[i]->nome);
       printf("Data Nascimento: %s\n", alunos[i]->data);
       printf("Curso: %s\n", alunos[i]->curso);
       printf("Periodo Ingresso: %s\n", alunos[i]->periodo);
       printf("%% Conclusao do Curso: %d\n", alunos[i]->percConclusao);
       printf("CRA: %.2f\n", alunos[i]->coef);
    }
}