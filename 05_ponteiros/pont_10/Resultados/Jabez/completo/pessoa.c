#include "pessoa.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros para pai, mae e irmao com NULL.
 * 
 * @return Uma nova pessoa e sem pais e irmao.
 */
tPessoa CriaPessoa(){

    tPessoa p;
    p.nome[0] = '\0';
    p.pai  = NULL;
    p.mae = NULL;
    p.irmao = NULL;

    return p;

}

/**
 * @brief Lê os dados de uma pessoa.
 * 
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */
void LePessoa(tPessoa *pessoa){

    
    char nome[100];
    scanf(" %[^\n]\n",nome);

    strcpy(pessoa->nome,nome);

}

/**
 * @brief Verifica se uma pessoa tem pai e/ou mae associado(s).
 * Ou seja, verifica pelo menos um dos ponteiros pai e mae é diferente de NULL.
 * 
 * @param pessoa Ponteiro para a pessoa a ser verificada.
 * 
 * @return 1 se a pessoa tiver pai e/ou mae associado(s) e 0 caso contrário.
*/
int VerificaSeTemPaisPessoa(tPessoa *pessoa){

    if(pessoa->pai == NULL && pessoa->mae == NULL){
        return 0;
    }
    return 1;

}

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mae associado(s).
 * Dica: use a função VerificaSeTemPaisPessoa para verificar se a pessoa tem pai e/ou mae associado(s).
 * Alem disso, imprimir o nome do irmao caso exista.
 * 
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa){

    
    if(VerificaSeTemPaisPessoa(pessoa)){
        printf("NOME COMPLETO: %s\n",pessoa->nome);
        if(pessoa->pai == NULL){
            printf("PAI: NAO INFORMADO\n");
        }else{
            printf("PAI: %s\n",pessoa->pai->nome);
        }
        if(pessoa->mae == NULL){
            printf("MAE: NAO INFORMADO\n");
        }else{
            printf("MAE: %s\n",pessoa->mae->nome);
        }
        if(pessoa->irmao == NULL){
            printf("IRMAO: NAO INFORMADO\n");
        }else{
            printf("IRMAO: %s\n",pessoa->irmao->nome);
        }
        printf("\n");
    }
}

/**
 * @brief Verifica se duas pessoas são irmãos, ou seja, se os ponteiros pai e mae são iguais.
 * 
 * @param pessoa1 Ponteiro para a primeira pessoa.
 * @param pessoa2 Ponteiro para a segunda pessoa.
 * 
 * @return 1 se as pessoas forem irmãos e 0 caso contrário.
*/
int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2){

    return pessoa1->pai == pessoa2->pai && pessoa1->mae == pessoa2->mae;

}


/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a representar as associacoes lidas
 * 
 * Apos a associado dos pais, voce deve verificar se ha irmaos e associar os irmaos.
 * 
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 * @param numPessoas Numero de pessoas a serem associadas (tamanho do vetor).
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas){

    int ass;

    scanf("%d ",&ass);

    for(int i = 0; i < ass; ++i){

        int m,p,f;
        scanf("mae: %d, pai: %d, filho: %d ",&m,&p,&f);

        if(p!=-1){
            pessoas[f].pai = &pessoas[p];
        }
        if(m!=-1){
            pessoas[f].mae = &pessoas[m];
        }

    }

    for(int i = 0; i< numPessoas; i++){

        for(int j = 0; j < numPessoas; j++){

            if(i!=j){

                if(VerificaIrmaoPessoa(&pessoas[i],&pessoas[j])){

                    pessoas[i].irmao = &pessoas[j];
                    pessoas[j].irmao = &pessoas[i];

                }
            }
        }
    }
}

