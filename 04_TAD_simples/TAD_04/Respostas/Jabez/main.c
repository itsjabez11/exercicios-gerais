#include "aluno.h"
#include <stdio.h>

int main(){

    int qtd;

    scanf("%d ",&qtd);

    tAluno a[qtd];
    for(int i = 0; i < qtd; i++){
        a[i] = LeAluno();
    }

    tAluno aux;
    int i,j;
    for(i = 0; i< qtd-1; i++){

        for(j = 0; j<qtd -i-1; j++){
            if(ComparaMatricula(a[j],a[j+1])==1){
                aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
            }
        }
    }
    for(i = 0; i< qtd; i++){
        if(VerificaAprovacao(a[i])){
            ImprimeAluno(a[i]);
        }
    }
    return 0;
}

