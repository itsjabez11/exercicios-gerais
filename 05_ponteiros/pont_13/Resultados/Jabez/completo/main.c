#include "rolagem.h"
#include <stdio.h>



void alterar(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int * numMsgs);

void imprimir(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int * numMsgs);

int main()
{
    int repeat = 0, qtd = 0;

    scanf("%d ",&repeat);

    scanf("%d", &qtd);

    char msg[qtd][TAM_MAX_MSG];

    for(int i = 0; i < qtd; ++i){

        scanf("%[^\n] ",msg[i]);

    }
    FptrMsg print;
    print = imprimir;
    RolaMsg(print,30,repeat);

}
void imprimir(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int * numMsgs){
    
    for(int i = 0; i < *numMsgs; i++){

        printf("%s",msg[i]);

    }
    printf("\n");

}