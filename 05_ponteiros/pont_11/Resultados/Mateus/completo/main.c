#include <stdio.h>
#include "calculadora.h"

float Calcular(float num1, float num2, CalculatoraCallback operacao){
    return operacao(num1, num2);
}

float soma(float n1, float n2){
    return n1 + n2;
}

float sub(float n1, float n2){
    return n1 - n2;
}

float mult(float n1, float n2){
    return n1 * n2;
}

float div(float n1, float n2){
    return n1 / n2;
}

int main(){
    char op;
    float num1, num2;
    

    while(1){
    scanf("%c\n", &op);

    if(op=='f'){
        break;
    }

    scanf("%f %f\n", &num1, &num2);

    switch (op)
    {
    case 'a':
        printf("%.2f + %.2f = %.2f\n", num1, num2, Calcular(num1, num2, soma));
        break;

    case 's':
        printf("%.2f - %.2f = %.2f\n", num1, num2, Calcular(num1, num2, sub));
        break;

    case 'm':
        printf("%.2f x %.2f = %.2f\n", num1, num2, Calcular(num1, num2, mult));
        break;

    case 'd':
        printf("%.2f / %.2f = %.2f\n", num1, num2, Calcular(num1, num2, div));
        break;

    }
    }
}