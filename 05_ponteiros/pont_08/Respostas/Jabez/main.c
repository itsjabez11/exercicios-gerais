#include "tDepartamento.h"
#include <stdio.h>


int main()
{

    int n;
    
    scanf("%d ",&n);

    tDepartamento vetor_depto[n];
    printf("\n");
    for(int i = 0; i < n; i++){
    
        char curso1[STRING_MAX];
        char curso2[STRING_MAX];
        char curso3[STRING_MAX];
        char diretor[STRING_MAX];
        char nome[STRING_MAX];
        int m1 , m2 , m3;
        while(1){

            scanf(" %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %d %d %d",nome,diretor,curso1,curso2,curso3,&m1,&m2,&m3);
            if(m1 <0 || m2 < 0 || m3< 0){
                printf("Digite um departamento com médias válidas\n");
            }else{
                vetor_depto[i] = CriaDepartamento(curso1,curso2,curso3,nome,m1,m2,m3,diretor);
            }
        }
        
        

    }

    OrdenaDepartamentosPorMedia(vetor_depto,n);

    for(int i = 0; i < n; i++){

        ImprimeAtributosDepartamento(vetor_depto[i]);

    }
    
    return 0;

}