#include "data.h"

void InicializaDataParam( int dia, int mes, int ano, tData *data){
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
}

void LeData( tData *data ){
    scanf("%d %d %d\n", &data->dia, &data->mes, &data->ano);
}

void ImprimeData( tData *data ){
    printf("'%02d/%02d/%04d'\n", data->dia, data->mes, data->ano);
}

int EhBissexto( tData *data ){
    if(data->ano % 4 == 0){
        return 1;
    }
    return 0;
}

int InformaQtdDiasNoMes( tData *data ){
    if(data->mes == 2){
        if(EhBissexto(data)){
            return 29;
        } else {
            return 28;
        }
    }

    if (data->mes == 1 || data->mes == 3 || data->mes == 5 || data->mes == 7 ||
    data->mes == 8 || data->mes == 10 || data->mes == 12) {
        return 31;
    }

    if (data->mes == 4 || data->mes == 6 || data->mes == 9 || data->mes == 11) {
        return 30;
    }
}

void AvancaParaDiaSeguinte( tData *data ){
    if(data->dia == InformaQtdDiasNoMes(data) && data->mes != 12){
        data->mes++;
        data->dia = 1;
    } else if(data->mes == 12 && data->dia == 31){
        data->dia = 1;
        data->mes = 1;
        data->ano++;
    } else {
        data->dia++;
    }
}

int EhIgual( tData *data1, tData *data2 ){
    if(data1->dia == data2->dia && data1->mes == data2->mes && data1->ano == data2->ano){
        return 1;
    } else {
        return 0;
    }
}