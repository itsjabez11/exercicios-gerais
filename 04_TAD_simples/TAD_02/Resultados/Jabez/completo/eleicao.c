#include <stdio.h>
#include "eleicao.h"
#include "candidato.h"
#include "eleitor.h"




/**
 * @brief Inicializa uma eleição com valores padrão (zerando os votos invalidos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados.
 * @return Eleição inicializada.
 */
tEleicao InicializaEleicao(){
    int totC = 0, i;
    tEleicao e;
    e.totalPresidentes = 0;
    e.totalGovernadores = 0;
    e.votosBrancosPresidente = 0;
    e.votosNulosPresidente = 0;
    e.votosBrancosGovernador = 0;
    e.votosNulosGovernador = 0;
    e.totalEleitores = 0;
    scanf("%d ",&totC);
    for(i = 0; i< totC; i++){
        tCandidato c = LeCandidato();
        if(ObtemCargo(c)=='P'){
            e.presidentes[e.totalPresidentes] = CriaCandidato(c.nome,c.partido,c.cargo,c.id);
            e.totalPresidentes++;
            
        }else if(ObtemCargo(c)=='G'){
            e.governadores[e.totalGovernadores] = CriaCandidato(c.nome,c.partido,c.cargo,c.id);
            e.totalGovernadores++;
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

    int totE = 0, i,j;
    scanf("%d ",&totE);

    
    for(i = 0; i<totE; i++){
        tEleitor e =  LeEleitor();
        for(j = 0; j< eleicao.totalEleitores; j++){
            if(i!=j && EhMesmoEleitor(e,eleicao.eleitores[j])){
                eleicao.totalEleitores = -1;
                return eleicao;
            }
        }
        int votoP = ObtemVotoPresidente(e);
        int votoG = ObtemVotoGovernador(e);
        int votouP = 0;
        int votouG = 0;
        if(votoP!=0){
            
            for(j = 0; j<eleicao.totalPresidentes; j++){
                
            if(VerificaIdCandidato(eleicao.presidentes[j],votoP)){
                eleicao.presidentes[j] = IncrementaVotoCandidato(eleicao.presidentes[j]);
                votouP = 1;
                break;
                }
            }
            if(!votouP){
                eleicao.votosNulosPresidente++;
            }
        }else{
            eleicao.votosBrancosPresidente++;
        }
        

        if(votoG!=0){
            votouG = 0;
            for(j = 0; j<eleicao.totalGovernadores; j++){
                
            if(VerificaIdCandidato(eleicao.governadores[j],votoG)){
                eleicao.governadores[j] = IncrementaVotoCandidato(eleicao.governadores[j]);
                votouG = 1;
                break;
                }
            }
            if(!votouG){
                eleicao.votosNulosGovernador++;
            }
        }else{
            eleicao.votosBrancosGovernador++;
        }
        eleicao.eleitores[i] = CriaEleitor(e.id,e.votoP,e.votoG);
        eleicao.totalEleitores++;
    }
    return eleicao;
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao eleicao){

    if(eleicao.totalEleitores ==-1){
        printf("ELEICAO ANULADA\n");
        return ;
    }else if(eleicao.totalEleitores>MAX_ELEITORES){
        printf("ELEICAO ANULADA\n");
        return ;
    }

    if(eleicao.totalGovernadores>MAX_CANDIDATOS_POR_CARGO){
        printf("ELEICAO ANULADA\n");
        return ;
    }
    if(eleicao.totalPresidentes>MAX_CANDIDATOS_POR_CARGO){
        printf("ELEICAO ANULADA\n");
        return ;
    }
    int totalInvalidoP = eleicao.votosBrancosPresidente+eleicao.votosNulosPresidente;
    int totalInvalidoG = eleicao.votosBrancosGovernador+eleicao.votosNulosGovernador;

    int i = 0;
    int totalValidoP = 0;
    int totalValidoG = 0;
    int idMelhorP = 0;
    int qtdMelhorP = 0;
    int idMelhorG = 0;
    int qtdMelhorG = 0;
    int empate = 0;
    for(i = 0; i<eleicao.totalPresidentes; i++){
        totalValidoP += ObtemVotos(eleicao.presidentes[i]);
        if(ObtemVotos(eleicao.presidentes[i])>qtdMelhorP){
            qtdMelhorP = ObtemVotos(eleicao.presidentes[i]);
            idMelhorP = i;
        }
    }
    int totalVotosP = totalValidoP+totalInvalidoP;
    float percentualP = CalculaPercentualVotos(eleicao.presidentes[idMelhorP],totalVotosP);
    printf("- PRESIDENTE ELEITO: ");
    
        empate = 0;
        for(i = 0; i<eleicao.totalPresidentes; i++){
            if(ObtemVotos(eleicao.presidentes[i])==qtdMelhorP){
                if(!EhMesmoCandidato(eleicao.presidentes[idMelhorP],eleicao.presidentes[i])){
                    printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
                    empate = 1;
                    break;
                }
            }
        }
        if(!empate){
            if(qtdMelhorP<totalInvalidoP){
                printf("SEM DECISAO\n");
            }else{
                ImprimeCandidato(eleicao.presidentes[idMelhorP],percentualP);
                printf("\n");
            }
            
        }
    
    
    
    for(i = 0; i<eleicao.totalGovernadores; i++){
        totalValidoG += ObtemVotos(eleicao.governadores[i]);
        if(ObtemVotos(eleicao.governadores[i])>qtdMelhorG){
            qtdMelhorG = ObtemVotos(eleicao.governadores[i]);
            idMelhorG = i;
        }
    }
    int totalVotosG = totalValidoG+totalInvalidoG;
    float percentualG = CalculaPercentualVotos(eleicao.governadores[idMelhorG],totalVotosG);
    printf("- GOVERNADOR ELEITO: ");
    
        empate = 0;
        for(i = 0; i<eleicao.totalGovernadores; i++){
            if(ObtemVotos(eleicao.governadores[i])==qtdMelhorG){
                if(!EhMesmoCandidato(eleicao.governadores[idMelhorG],eleicao.governadores[i])){
                    printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
                    empate = 1;
                    break;
                }
            }
        }
        if(!empate){
            if(qtdMelhorG<totalInvalidoG){
                printf("SEM DECISAO\n");
            }else{
                ImprimeCandidato(eleicao.governadores[idMelhorG],percentualG);
                printf("\n");
            }
            
        }
    int totalNulo = eleicao.votosNulosPresidente+eleicao.votosNulosGovernador;
    int totalBranco = eleicao.votosBrancosPresidente+eleicao.votosBrancosGovernador;
    printf("- NULOS E BRANCOS: %d, %d\n",totalNulo,totalBranco);
    
}


