#include "paciente.h"
#include <stdio.h>
#include "lesao.h"
#include <string.h>

int main(){

    int totalPacientes = 0;
    int media = 0;
    int totalLesoes = 0;
    int totalCirurgias = 0;

    Paciente pacientes[10];

    Data dataBase = criaData(12,9,2023);

    char cartaoSus[MAX_CARTAO_SUS];

    char option = '\0';

    while(1){
        
        scanf("%c\n",&option);

        if(option=='F'){

            break;

        }
        if(option=='P'){
            Paciente p = lerPaciente();
            pacientes[totalPacientes++] = p;
        }else if(option=='L'){
            Lesao l = lerLesao();
                
                for(int i = 0; i<totalPacientes; i++){
                    
                    getCartaoSusLesao(l,cartaoSus);
                    if(!strcmp(cartaoSus,pacientes[i].cartaoSus)){

                        totalLesoes++;
                        pacientes[i] = vinculaLesaoPaciente(pacientes[i],l);
                        break;
                    }
                    
                    
                }
        }else if(option=='F'){

            break;
        }else{
            return 0;
        }
        }
    if(totalPacientes==0){
        printf("TOTAL PACIENTES: %d\n",totalPacientes);
        printf("MEDIA IDADE (ANOS): -\n");
        printf("TOTAL LESOES: %d\n",totalLesoes);
        printf("TOTAL CIRURGIAS: %d\n",totalCirurgias);
        printf("LISTA DE PACIENTES:");
        return 0;
    }
    for(int i = 0; i< totalPacientes; i++){

        media += calculaIdadePaciente(pacientes[i],dataBase);

        

        totalCirurgias += qtdLesoesCirurgicasPaciente(pacientes[i]);

    }

    media /= totalPacientes;
    
    printf("TOTAL PACIENTES: %d\n",totalPacientes);
    printf("MEDIA IDADE (ANOS): %d\n",media);
    printf("TOTAL LESOES: %d\n",totalLesoes);
    printf("TOTAL CIRURGIAS: %d\n",totalCirurgias);
    printf("LISTA DE PACIENTES:\n");

    for(int i = 0; i < totalPacientes; i++){

        imprimePaciente(pacientes[i]);

    }
    
   
    return 0;
}