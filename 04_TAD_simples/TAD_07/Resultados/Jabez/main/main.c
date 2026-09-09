#include "data.h"
#include <stdio.h>


int main(){

    int dia1,m1,a1,dia2,m2,a2;
    scanf("%02d/%02d/%04d ",&dia1,&m1,&a1);
    tData d1 = CriaData(dia1,m1,a1);
    scanf("%02d/%02d/%04d ",&dia2,&m2,&a2);
    tData d2 = CriaData(dia2,m2,a2);
    if(VerificaDataValida(d1) && VerificaDataValida(d2)){
        printf("Primeira data: ");
        ImprimeDataExtenso(d1);
        printf("Segunda data: ");
        ImprimeDataExtenso(d2);

    }else{
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return 0;
    }
    if(ComparaData(d1,d2)==1){
        printf("A segunda data eh mais antiga\n");
    }else if(ComparaData(d1,d2)==-1){
        printf("A primeira data eh mais antiga\n");
    }else{
        printf("As datas sao iguais\n");
    }
    int diff = CalculaDiferencaDias(d1,d2);
    printf("A diferenca em dias entre as datas eh: %02d dias",diff);

    return 0;
}