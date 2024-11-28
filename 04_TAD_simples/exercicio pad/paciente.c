#include <stdio.h>
#include "paciente.h"
#include "data.h"

Paciente lePaciente() {
    Paciente var;
    scanf("%[^\n]\n", var.nome);
    var.data = leData();
    scanf("%[^\n]\n", var.cartao);
    scanf("%c\n", &var.genero);

    return var;
}