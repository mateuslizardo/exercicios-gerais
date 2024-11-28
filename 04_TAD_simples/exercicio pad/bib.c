#include <stdio.h>
#include "bib.h"
#include <string.h>
#include "constantes.h"

char cadastro() {
    char c;
    scanf("%c\n", &c);
    return c;
}

int cartaoDeQuem(Paciente paciente) {
    char sus[TAM_SUS];
    fgets(sus, TAM_SUS, stdin);
    if(strcmp(paciente.cartao, sus) == 0){
        return True;
    }
    return False;
}