#include <stdio.h>

#include "candidato.h"
#include "eleitor.h"


#define MAX_CANDIDATOS_POR_CARGO 3
#define MAX_ELEITORES 10

typedef struct {
    tCandidato presidentes[MAX_CANDIDATOS_POR_CARGO];
    int totalPresidentes;

    tCandidato governadores[MAX_CANDIDATOS_POR_CARGO];
    int totalGovernadores;

    int votosBrancosPresidente;
    int votosNulosPresidente;

    int votosBrancosGovernador;
    int votosNulosGovernador;

    tEleitor eleitores[MAX_ELEITORES];
    int totalEleitores;
    
} tEleicao;

/**
 * @brief Inicializa uma eleição com valores padrão (zerando os votos invalidos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados.
 * @return Eleição inicializada.
 */
tEleicao InicializaEleicao(){
    tEleicao e;
    int tot = 0;
    scanf("%d" ,&tot);
    int i = 0;

    e.totalGovernadores = 0;
    e.totalPresidentes = 0;
    e.totalEleitores = 0;
    e.votosBrancosGovernador = 0;
    e.votosNulosPresidente = 0;
    e.votosBrancosPresidente = 0;
    e.votosNulosGovernador = 0;
    
    tCandidato c[tot];
    for(i = 0; i<tot; i++){
        c[i] = LeCandidato();
        if(c[i].cargo=='G'){
            e.governadores[e.totalPresidentes] = c[i];
            e.totalGovernadores++;
        }else if(c[i].cargo=='P'){
            e.presidentes[e.totalPresidentes] = c[i];
            e.totalPresidentes++;
        }
    }
    return e;
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada.
 * @return Eleição com os resultados da votação.
 */
tEleicao RealizaEleicao(tEleicao eleicao){
    int i = 0;
    scanf("%d ",&eleicao.totalEleitores);
    int j = 0;
    int votoG = 0, votoP = 0;
    int naoEhNulo = 0;
    for(i = 0; i < eleicao.totalEleitores; i++){
        naoEhNulo = 0;
        eleicao.eleitores[i] = LeEleitor();
        votoG = ObtemVotoGovernador(eleicao.eleitores[i]);
        votoP = ObtemVotoPresidente(eleicao.eleitores[i]);
        if(votoG==0){
            eleicao.votosBrancosGovernador++;
        }else{
            for(j = 0; j< eleicao.totalGovernadores; j++){
                if(VerificaIdCandidato(eleicao.governadores[j],votoG)){
                    eleicao.governadores[j] = IncrementaVotoCandidato(eleicao.governadores[j]);
                    naoEhNulo = 1;
                }
                if(!naoEhNulo){
                    eleicao.votosNulosGovernador++;
                }
            }
        }
        naoEhNulo = 0;
        if(votoP==0){
            eleicao.votosBrancosPresidente++;
        }else{
            for(j = 0; j< eleicao.totalPresidentes; j++){
                if(VerificaIdCandidato(eleicao.presidentes[i],votoP)){
                    eleicao.presidentes[j] = IncrementaVotoCandidato(eleicao.presidentes[j]);
                    naoEhNulo = 1;
                }
                if(!naoEhNulo){
                    eleicao.votosNulosPresidente++;
                }
            }
        }
        eleicao.totalEleitores++;
    }
    int vmelhorP = 0;
    int idmelhorP = 0;
    int idmelhorG = 0;
    int vmelhorG = 0;
    for(i = 0; i< eleicao.totalPresidentes; i++){
        if(ObtemVotos(eleicao.presidentes[i])>vmelhorP){
            vmelhorP = ObtemVotos(eleicao.presidentes[i]);
            idmelhorP = eleicao.presidentes[i].id;
        }
    }
    
    return eleicao;
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao eleicao){

    int i= 0,j = 0;
    for(i = 0; i<eleicao.totalEleitores; i++){
        for(j = 1; j<eleicao.totalEleitores; j++){
            if(EhMesmoEleitor(eleicao.eleitores[i],eleicao.eleitores[j])){
                printf("ELEICAO ANULADA\n");
                return ;
            }
        }
    }
    if(eleicao.totalEleitores>MAX_ELEITORES){
        printf("ELEICAO ANULADA\n");
        return ;
    }
    if(eleicao.totalGovernadores> MAX_CANDIDATOS_POR_CARGO || eleicao.totalPresidentes > MAX_CANDIDATOS_POR_CARGO){
        printf("ELEICAO ANULADA\n");
        return ;
    }


}

