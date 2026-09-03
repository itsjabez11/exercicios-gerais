#include "jogada.h"
#include "jogador.h"
#include "tabuleiro.h"
#include <stdio.h>
#include "jogo.h"

/**
 * Cria um jogo e retorna o jogo criado.
 * 
 * @return o jogo criado.
 */


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */

tJogo CriaJogo(){
    tJogo jogo;
    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);
    return jogo;
}
void ComecaJogo(tJogo jogo){

    int i = 0;
    while(!AcabouJogo(jogo)){
        
        if(i%2==0){
            jogo.tabuleiro = JogaJogador(jogo.jogador1,jogo.tabuleiro);
        }else{
            jogo.tabuleiro = JogaJogador(jogo.jogador2,jogo.tabuleiro);
        }
        ImprimeTabuleiro(jogo.tabuleiro);
        i++;
    }
    
}


/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 * 
 * @param jogo o jogo atual.
 * 
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo jogo){
    if(VenceuJogador(jogo.jogador1,jogo.tabuleiro)){
        printf("JOGADOR 1 Venceu!\n");
        return 1;
    }else if(VenceuJogador(jogo.jogador2,jogo.tabuleiro)){
        printf("JOGADOR 2 Venceu!\n");
        return 1;
    }else if(!TemPosicaoLivreTabuleiro(jogo.tabuleiro)){
        printf("Sem vencedor!\n");
        return 1;
    }
    return 0;
}


/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo(){
    char answer;
    printf("Jogar novamente? (s,n)\n");
    scanf(" %c",&answer);
    if(answer=='s'){
        return 1;
    }
    return 0;
}

