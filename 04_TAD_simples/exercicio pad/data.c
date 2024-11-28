#include "data.h"
#include <stdio.h>

Data leData(){
    Data var;
    scanf("%d/%d/%d\n", &var.dia, &var.mes, &var.ano);
    
    return var;
}