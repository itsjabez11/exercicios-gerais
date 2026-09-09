#include "departamento.h"
#include <stdio.h>


int main(){

    int qtd;
    scanf("%d ",&qtd);

    tDepartamento d[qtd];

    for(int i = 0; i< qtd; i++){
        char nome [STRING_MAX];     // nome do departamento
        char c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX];    // nomes dos cursos do departamento
        int m1, m2, m3;     // médias de notas dos cursos do departamento
        char diretor [STRING_MAX];    // nome do diretor do departamento
        
        scanf("%[^\n]",nome);
        scanf(" %[^\n]",diretor);
        scanf(" %[^\n]", c1);
        scanf(" %[^\n]", c2);
        scanf(" %[^\n]", c3);
        scanf(" %d %d %d ",&m1,&m2,&m3);
        if(validaMediaDepartamento(m1) && validaMediaDepartamento(m2) && validaMediaDepartamento(m3)){
            d[i] = criaDepartamento(c1,c2,c3,nome,m1,m2,m3,diretor);
        }
    }
    ordenaPorMediaDepartamentos(d,qtd);

    for(int i = 0; i < qtd; i++){
        printf("ATRIBUTOS: \n");
        imprimeAtributosDepartamento(d[i]);

    }
    return 0;
}