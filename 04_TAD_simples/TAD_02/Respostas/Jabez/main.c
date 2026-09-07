#include <stdio.h>
#include "eleicao.h"
#include "eleitor.h"
#include "candidato.h"


int main(){
    tEleicao e = InicializaEleicao();
    e = RealizaEleicao(e);
    ImprimeResultadoEleicao(e);
    return 0;
}