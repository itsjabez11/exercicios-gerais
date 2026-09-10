#include "biblioteca.h"
#include <stdio.h>


void imprimeUI();

int main(){


    tBiblioteca b = inicializarBiblioteca();
    int qtd;
    scanf("%d ",&qtd);

    imprimeUI();
    for(int i = 0; i < qtd; i++){

        int op;
        

        scanf("%d ",&op);
        if(op==1){
            tLivros l = lerLivro();
            

            b = adicionarLivroNaBiblioteca(b,l);

            
            
        }else if(op ==2){
            char titulo[100];
            scanf("%[^\n] ",titulo);
            b = removerLivroDaBiblioteca(b,titulo);
        }else if(op == 3){
            
            listarLivrosDaBiblioteca(b);
            
            
        }else{
            
            printf("Operacao invalida!\n");
            return 0;
        }
    }
    return 0;
}
void imprimeUI(){

    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n");
    printf("\n");

}