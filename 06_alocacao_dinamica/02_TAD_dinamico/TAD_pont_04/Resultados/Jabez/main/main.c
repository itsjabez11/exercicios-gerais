#include <stdio.h>
#include "aluno.h"
#include <stdlib.h>
#include <string.h>

int main()
{

    int n;
    scanf("%d",&n);

    tAluno **alunos = malloc(n*sizeof(tAluno*));

    for(int i = 0; i < n; ++i){

        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);

    } 
    

    for(int i = 0; i < n-1; ++i){
        
        
        for(int j =0; j < n-1-i; ++j){

            if(ComparaMatricula(alunos[j],alunos[j+1])==1){

                tAluno *aux = alunos[j];
                alunos[j] = alunos[j+1];
                alunos[j+1] = aux;
            
            }

        }
        
        
    }   
    for(int i = 0; i < n; i++){

        if(VerificaAprovacao(alunos[i])){

            ImprimeAluno(alunos[i]);

        }
        ApagaAluno(alunos[i]);
    }
    free(alunos);


    return 0;
}