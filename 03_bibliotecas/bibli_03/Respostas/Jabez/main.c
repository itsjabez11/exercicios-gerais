#include "data.h"
#include <stdio.h>

int main(){
    int d1,m1,a1,d2,m2,a2;
    scanf("%02d/%02d/%04d",&d1,&m1,&a1);
    scanf("%02d/%02d/%04d",&d2,&m2,&a2);
    if(verificaDataValida(d1,m1,a1) && verificaDataValida(d2,m2,a2)){
        printf("Primeira data: ");
        imprimeDataExtenso(d1,m1,a1);
        printf("Segunda data: ");
        imprimeDataExtenso(d2,m2,a2);
        if(comparaData(d1,m1,a1,d2,m2,a2)==1){
            printf("A segunda data eh mais antiga\n");
        }else if(comparaData(d1,m1,a1,d2,m2,a2)==-1){
            printf("A primeira data eh mais antiga\n");
        }else{
            printf("As datas sao iguais\n");
        }
        int diff = calculaDiferencaDias(d1,m1,a1,d2,m2,a2);
        printf("A diferenca em dias entre as datas eh: %02d dias\n",diff);
    }else{
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    }
    return 0;
}