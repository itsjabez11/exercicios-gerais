#include "matrix_utils.h"
#include <stdio.h>


void imprimeUI();

int main(){
    int rows1,cols1,rows2,cols2;
    scanf("%d %d",&rows1,&cols1);
    int matrix1[rows1][cols1];
    matrix_read(rows1,cols1,matrix1);
    scanf("%d %d",&rows2,&cols2);
    int matrix2[rows2][cols2];
    matrix_read(rows2,cols2,matrix2);

    int choose = 0;

    

    int escolha,scalar;
    while(choose!=6){
        int result[100][100] = {{0}};
        imprimeUI();
        scanf("%d",&choose);

        switch (choose){
            case 1:{
                if(possible_matrix_sum(rows1,cols1,rows2,cols2)){
                    matrix_add(rows1,cols1,matrix1,rows2,cols2,matrix2,result);
                    matrix_print(rows1,cols1,result);
                }else{
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                    printf("\n");
                }
                break;
            }
            case 2:{
                if(possible_matrix_sub(rows1,cols1,rows2,cols2)){
                    matrix_sub(rows1,cols1,matrix1,rows2,cols2,matrix2,result);
                    matrix_print(rows1,cols1,result);
                }else{
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                    printf("\n");
                }
                break;
            }
            case 3:{
                if(possible_matrix_multiply(cols1,rows2)){
                    matrix_multiply(rows1,cols1,matrix1,rows2,cols2,matrix2,result);
                    matrix_print(rows1,cols2,result);
                }else{
                    printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
                    printf("\n");
                }
                break;
            }
            case 4:{
                scanf("%d %d",&scalar,&escolha);
                if(escolha==1){
                    scalar_multiply(rows1,cols1,matrix1,scalar);
                    matrix_print(rows1,cols1,matrix1);
                }else if(escolha==2){
                    scalar_multiply(rows2,cols2,matrix2,scalar);
                    matrix_print(rows2,cols2,matrix2);
                }
                break;
            }
            case 5:{
                transpose_matrix(rows1,cols1,matrix1,result);
                matrix_print(cols1,rows1,result);
                transpose_matrix(rows2,cols2,matrix2,result);
                matrix_print(cols2,rows2,result);
                break ;
            }
        }
    }
}

void imprimeUI(){
    
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida:\n");
}
