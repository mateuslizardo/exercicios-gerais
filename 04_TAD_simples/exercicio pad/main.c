#include <stdio.h>
#include "lesao.h"
#include "data.h"
#include "paciente.h"
#include "bib.h"
#include "constantes.h"

int main() {
    Paciente pacientes[STD_TAM];
    int cont_pacientes = 0;

    while(1){
        char c = cadastro();
        switch(c) {
            case 'P':
                pacientes[cont_pacientes] = lePaciente();
                break;
            
            case 'L':
                for(int i = 0; i < cont_pacientes; i++){
                    if(cartaoDeQuem(pacientes[i])) {
                        pacientes[i].cont_lesao++;
                        pacientes[i].lesao[pacientes[i].cont_lesao] = leLesao();
                        break;
                    }
                }
                break;

            case 'F':
                
        }
        cont_pacientes++;
    }

}