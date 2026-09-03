#include <stdio.h>
#include "tabuleiro.h"
#include "jogada.h"
#include "jogo.h"
#include "jogador.h"

int main(){

    while(1){
        tJogo jogo = CriaJogo();
        ComecaJogo(jogo);
        if(!ContinuaJogo()){
            break;
        }
    }
    return 0;
}