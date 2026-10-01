#include "tela.h"
#include <stdio.h>
#include <string.h>
#include "botao.h"

void executeOptions();

void executeSave();

void executeDelete();

int main()
{
    Tela t = CriarTela(200,400);

    Botao b1 = CriarBotao("Salvar",12,"FFF",1,executeSave);
    Botao b2 = CriarBotao("Excluir",18,"000",1,executeDelete);
    Botao b3 = CriarBotao("Opcoes",10,"FF0000",2,executeOptions);

    RegistraBotaoTela(&t,b1);
    RegistraBotaoTela(&t,b2);
    RegistraBotaoTela(&t,b3);
    
    DesenhaTela(t);
    OuvidorEventosTela(t);

    return 0;
}

void executeOptions(){

    printf("- Botao de OPCOES ativado!\n");
}

void executeSave(){

    printf("- Botao de SALVAR dados ativado!\n");

}

void executeDelete(){

    printf("- Botao de EXCLUIR dados ativado!\n");

}