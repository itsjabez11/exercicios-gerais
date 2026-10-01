#include "vetor.h"
#include <stdio.h>


int s(int n1, int n2);

int m(int n1, int n2);

int main()
{

    Vetor v;
    LeVetor(&v);

    

    int sum = 0, multiply = 1;

    sum = AplicarOperacaoVetor(&v,s);
    multiply = AplicarOperacaoVetor(&v,m);
    printf("Soma: %d\n",sum);
    printf("Produto: %d\n",multiply);

    return 0;
}

int s(int n1, int n2){

    return n1+n2;

}

int m(int n1, int n2){

    return n1*n2;

}