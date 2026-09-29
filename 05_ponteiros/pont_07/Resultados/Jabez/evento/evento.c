#include "evento.h"
#include <string.h>
#include <stdio.h>

/**
 * Cadastra um novo evento no calendário e o insere na próxima posição do array.
 *
 * @param eventos Array de eventos onde o novo evento será cadastrado.
 * @param numEventos Ponteiro para o número atual de eventos cadastrados.
 */
void cadastrarEvento(Evento* eventos, int* numEventos){

    char nome[50];
    int d,m,a;
    if(*numEventos < MAX_EVENTOS){

        scanf("%49s %d %d %d ",nome,&d,&m,&a);
        
        Evento e;

        strcpy(e.nome,nome);

        e.dia = d;
        e.mes = m;
        e.ano = a;
        eventos[*numEventos] = e;

        (*numEventos)++;

        printf("Evento cadastrado com sucesso!\n");

    }else{

        printf("Limite de eventos atingido!\n");

    }
    

}

/**
 * Exibe todos os eventos cadastrados no calendário.
 *
 * @param eventos Array de eventos a serem exibidos.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void exibirEventos(Evento* eventos, int* numEventos){

    if(*numEventos == 0){
        printf("Nenhum evento cadastrado.\n");
    }else{

        printf("Eventos cadastrados:\n");

        for(int i = 0; i< *numEventos; i++){

            printf("%d - %s - %02d/%02d/%04d\n",i,eventos[i].nome,eventos[i].dia,eventos[i].mes,eventos[i].ano);

        }
    }
    


}

/**
 * Troca a data de um evento específico no calendário.
 *
 * @param eventos Array de eventos onde o evento será modificado.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarDataEvento(Evento* eventos, int* numEventos){
    
    int idx;
    int nd,nm,na;

    scanf("%d ",&idx);

    if(*numEventos<=idx || idx<0){
        printf("Indice invalido!\n");
        return;
    }
    for(int i = 0; i < *numEventos; i++){

        if(i==idx){
            scanf("%d %d %d ",&nd,&nm,&na);

        eventos[i].dia = nd;
        eventos[i].mes = nm;
        eventos[i].ano = na;
        }
    }
    

    printf("Data modificada com sucesso!\n");

}

/**
 * Troca a posição de dois eventos, a partir do índice, dentro do array de eventos.
 *
 * @param eventos Array de eventos onde a troca será realizada.
 * @param indiceA Ponteiro para o primeiro índice.
 * @param indiceB Ponteiro para o segundo índice.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){


    if(0<=*indiceA && *indiceA<=10 && *indiceA < *numEventos
    && 0<=*indiceB && *indiceB<=10 && *indiceB < *numEventos){
        

        Evento aux;
        aux = eventos[*indiceA];
        eventos[*indiceA] = eventos[*indiceB];
        eventos[*indiceB] = aux;

        printf("Eventos trocados com sucesso!\n");

    }else{
        printf("Indices invalidos!\n");
    }
    

}


