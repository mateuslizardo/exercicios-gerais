#ifndef _PACIENTE_H
#define _PACIENTE_H

#include "constantes.h"
#include "data.h"
#include "lesao.h"

typedef struct {
    char nome[STD_TAM], cartao[TAM_SUS], genero;
    Data data;
    Lesao lesao[MAX_LESAO];
    int cont_lesao;
} Paciente;

Paciente lePaciente();

#endif