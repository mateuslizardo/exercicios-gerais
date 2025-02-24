#include "tadgen.h"

int main(){
    int n;
    Type t;
    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos: ");
    scanf("%d %d\n", &t, &n);
    tGeneric *g = CriaGenerico(t, n);
    LeGenerico(g);
    ImprimeGenerico(g);
    DestroiGenerico(g);
    return 0;
}