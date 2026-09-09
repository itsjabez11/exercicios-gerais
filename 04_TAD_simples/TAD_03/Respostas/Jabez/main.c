#include "locadora.h"
#include <stdio.h>
#include <string.h>

int main(){

    tLocadora l = criarLocadora();
    char choose[20];
    while(scanf("%s",choose)==1){
        if(!strcmp(choose,"Cadastrar")){
            l =lerCadastroLocadora(l);
        }else if(!strcmp(choose,"Alugar")){
            l = lerAluguelLocadora(l);
        }else if(!strcmp(choose,"Estoque")){
            l = ordenarFilmesLocadora(l);
            consultarEstoqueLocadora(l);
        }else if(!strcmp(choose,"Devolver")){
            l = lerDevolucaoLocadora(l);
        }
        
        
    }
    
        
        consultarLucroLocadora(l);
    
    

    return 0;
}