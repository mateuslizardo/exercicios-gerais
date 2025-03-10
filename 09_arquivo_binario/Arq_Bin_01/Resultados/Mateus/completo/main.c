#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

int main(){
    int numeroAlunos;
    printf("Digite o numero de alunos: ");
    scanf("%d\n", &numeroAlunos);
    Aluno **vet = CriaVetorAlunos(numeroAlunos);
    LeAlunos(vet, numeroAlunos);
    SalvaAlunosBinario(vet, "alunos.bin", numeroAlunos);
    Aluno **vet2 = CriaVetorAlunos(numeroAlunos);
    CarregaAlunosBinario(vet2, "alunos.bin");
    ImprimeAlunos(vet2, numeroAlunos);
    LiberaAlunos(vet, numeroAlunos);
    LiberaAlunos(vet2, numeroAlunos);

    return 0;
}