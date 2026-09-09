#include "conta.h"
#include <stdio.h>
#include <string.h>

int main(){

    int qtd;
    scanf("%d ",&qtd);

    int i=0,j,choose=1;

    tConta c[qtd];

    while(choose!=0){

        scanf("%d ",&choose);
        switch (choose){
            case 1:{
                int n;
                scanf("%d ",&n);
                float valor;
                scanf("%f ",&valor);
                for(j = 0; j< i; j++){
                    if(VerificaConta(c[j],n)){
                        c[j] = SaqueConta(c[j],valor);
                    }
                }
                break;
            }
            case 2:{
                int n;
                scanf("%d ",&n);
                float valor;
                scanf("%f ",&valor);
                for(j = 0; j< i; j++){
                    if(VerificaConta(c[j],n)){
                        c[j] = DepositoConta(c[j],valor);
                    }
                }
                break;
            }
            case 3:{
                if(i<qtd){
                    char nome[20];
                    char cpf[15];
                    int n;
                    scanf("%s %s %d",nome,cpf,&n);
                    tUsuario u = CriaUsuario(nome,cpf);
                    c[i] = CriaConta(n,u);
                    i++;
                }
                break;
            }
            case 4:{
                printf("===| Imprimindo Relatorio |===\n");
                for(j = 0; j<i ; j++){
                    ImprimeConta(c[j]);
                    printf("\n");
                }
                break;
            }
        }
    }
    return 0;
}