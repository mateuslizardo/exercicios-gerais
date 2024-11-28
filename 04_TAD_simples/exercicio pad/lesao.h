#ifndef _LESAO_H
#define _LESAO_H

#include "constantes.h"

typedef struct {
    char id[TAM_ID], diag[STD_TAM], regiao[STD_TAM];
    int malig;
} Lesao;

Lesao leLesao();

#endif