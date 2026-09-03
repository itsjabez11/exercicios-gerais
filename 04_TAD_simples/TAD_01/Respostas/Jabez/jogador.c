#include <stdio.h>
#include "jogada.h"
#include "jogador.h"
#include "tabuleiro.h"

#define ID_JOGADOR_1 1
#define ID_JOGADOR_2 2


/**
 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 * 
 * @param idJogador o id do jogador (1 ou 2).
 * 
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador){
    tJogador player;
    player.id = idJogador;
    return player;
}


/**
 * Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada do jogador.
 * 
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return o tabuleiro atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){
    tJogada jogada;
    

    while(1){
        printf("Jogador %d\n",jogador.id);
        
        jogada = LeJogada();
        int x = ObtemJogadaX(jogada);
        int y = ObtemJogadaY(jogada);
        if(FoiJogadaBemSucedida(jogada)){
            if(!EhPosicaoValidaTabuleiro(x,y)){
                printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n",x,y);
            }else{
                if(TemPosicaoLivreTabuleiro(tabuleiro)){
                    if(EstaLivrePosicaoTabuleiro(tabuleiro,x,y)){
                        printf("Jogada [%d,%d]!\n",x,y);
                        tabuleiro = MarcaPosicaoTabuleiro(tabuleiro,jogador.id,x,y);
                        
                        break;
                    }else{
                        printf("Posicao invalida (OCUPADA - [%d,%d] )!\n",x,y);
                    }
                }
            }
        }
    }
    return tabuleiro;
}


/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso contrário.
 * 
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){
    
    if(jogador.id==1){
        if((tabuleiro.posicoes[0][0]==tabuleiro.peca1 && tabuleiro.posicoes[0][1]==tabuleiro.peca1 && tabuleiro.posicoes[0][2]==tabuleiro.peca1)
    ||(tabuleiro.posicoes[0][0]==tabuleiro.peca1 && tabuleiro.posicoes[1][1]==tabuleiro.peca1 && tabuleiro.posicoes[2][2]==tabuleiro.peca1)
    ||(tabuleiro.posicoes[0][2]==tabuleiro.peca1 && tabuleiro.posicoes[1][1]==tabuleiro.peca1 && tabuleiro.posicoes[2][0]==tabuleiro.peca1)
    ||(tabuleiro.posicoes[0][0]==tabuleiro.peca1 && tabuleiro.posicoes[1][0]==tabuleiro.peca1 && tabuleiro.posicoes[2][0]==tabuleiro.peca1)
    ||(tabuleiro.posicoes[0][1]==tabuleiro.peca1 && tabuleiro.posicoes[1][1]==tabuleiro.peca1 && tabuleiro.posicoes[2][1]==tabuleiro.peca1)
    ||(tabuleiro.posicoes[0][2]==tabuleiro.peca1 && tabuleiro.posicoes[1][2]==tabuleiro.peca1 && tabuleiro.posicoes[2][2]==tabuleiro.peca1)
    ||(tabuleiro.posicoes[1][0]==tabuleiro.peca1 && tabuleiro.posicoes[1][1]==tabuleiro.peca1 && tabuleiro.posicoes[1][2]==tabuleiro.peca1)
    ||(tabuleiro.posicoes[2][0]==tabuleiro.peca1 && tabuleiro.posicoes[2][1]==tabuleiro.peca1 && tabuleiro.posicoes[2][2]==tabuleiro.peca1)){
        return 1;
    }
    }else if(jogador.id ==2){
        if((tabuleiro.posicoes[0][0]==tabuleiro.peca2 && tabuleiro.posicoes[0][1]==tabuleiro.peca2 && tabuleiro.posicoes[0][2]==tabuleiro.peca2)
    ||(tabuleiro.posicoes[0][0]==tabuleiro.peca2 && tabuleiro.posicoes[1][1]==tabuleiro.peca2 && tabuleiro.posicoes[2][2]==tabuleiro.peca2)
    ||(tabuleiro.posicoes[0][2]==tabuleiro.peca2 && tabuleiro.posicoes[1][1]==tabuleiro.peca2 && tabuleiro.posicoes[2][0]==tabuleiro.peca2)
    ||(tabuleiro.posicoes[0][0]==tabuleiro.peca2 && tabuleiro.posicoes[1][0]==tabuleiro.peca2 && tabuleiro.posicoes[2][0]==tabuleiro.peca2)
    ||(tabuleiro.posicoes[0][1]==tabuleiro.peca2 && tabuleiro.posicoes[1][1]==tabuleiro.peca2 && tabuleiro.posicoes[2][1]==tabuleiro.peca2)
    ||(tabuleiro.posicoes[0][2]==tabuleiro.peca2 && tabuleiro.posicoes[1][2]==tabuleiro.peca2 && tabuleiro.posicoes[2][2]==tabuleiro.peca2)
    ||(tabuleiro.posicoes[1][0]==tabuleiro.peca2 && tabuleiro.posicoes[1][1]==tabuleiro.peca2 && tabuleiro.posicoes[1][2]==tabuleiro.peca2)
    ||(tabuleiro.posicoes[2][0]==tabuleiro.peca2 && tabuleiro.posicoes[2][1]==tabuleiro.peca2 && tabuleiro.posicoes[2][2]==tabuleiro.peca2)){
        return 1;
    }
    }
    return 0;
}

