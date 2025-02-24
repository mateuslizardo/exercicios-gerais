#include "cela.h"
#include "prisao.h"
#include "prisioneiro.h"

int main(){
    char nome[MAXTAM_NOME];
    int n, capac;
    scanf("%[^\n]\n", nome);
    scanf("%d %d\n", &n, &capac);
    tPrisao p = criaPrisao(nome, n, capac);
    executaPrisao(&p);
    return 0;
}