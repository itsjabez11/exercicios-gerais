#include "empresa.h"
#include <stdio.h>

int main(){

    int qtd_e = 0;
    scanf("%d ",&qtd_e);
    tEmpresa e[qtd_e];

    for(int i = 0; i < qtd_e; i++){
        e[i] = leEmpresa();

    }

    for(int i = 0; i< qtd_e; i++){

        imprimeEmpresa(e[i]);

    }
    return 0;
}