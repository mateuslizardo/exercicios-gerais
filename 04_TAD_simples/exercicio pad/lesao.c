#include <stdio.h>
#include "lesao.h"

Lesao leLesao(){
    Lesao var;
    scanf("%[^\n]\n", var.id);
    scanf("%[^\n]\n", var.diag);
    scanf("%[^\n]\n", var.regiao);
    scanf("%d\n", &var.malig);

    return var;
}