#include "matrix_utils.h"
#include <stdio.h>


void imprimeUI();

int main(){

    int r1,c1,r2,c2;

    scanf("%d %d ",&r1,&c1);
    tMatrix matrix1 = MatrixCreate(r1,c1);
    matrix1 = MatrixRead(matrix1);

    scanf("%d %d ",&r2,&c2);
    tMatrix matrix2 = MatrixCreate(r2,c2);
    matrix2 = MatrixRead(matrix2);

    int choose = 0;

    while(choose!=6){
        imprimeUI();
        scanf("%d ",&choose);
        
        switch (choose){
            case 1:{
                if(PossibleMatrixSum(matrix1,matrix2)){
                    tMatrix r = MatrixAdd(matrix1,matrix2);
                    MatrixPrint(r);
                
                }else{
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }
                break;
            }
            case 2:{
                if(PossibleMatrixSub(matrix1,matrix2)){
                    tMatrix r = MatrixSub(matrix1,matrix2);
                    MatrixPrint(r);
                
                }else{
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }
                break;
            }
            case 3:{
                if(PossibleMatrixMultiply(matrix1,matrix2)){
                    tMatrix r = MatrixMultiply(matrix1,matrix2);
                    MatrixPrint(r);
                }else{
                    printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
                }
                break;
            }
            case 4:{
                int scalar,choose2;
                scanf("%d %d ",&scalar,&choose2);
                if(choose2==1){
                    matrix1 = MatrixMultiplyByScalar(matrix1,scalar);
                    MatrixPrint(matrix1);
                }else if(choose2==2){
                    matrix2 = MatrixMultiplyByScalar(matrix2,scalar);
                    MatrixPrint(matrix2);
                }
                break;
            }
            case 5:{
                tMatrix r1 = TransposeMatrix(matrix1);
                MatrixPrint(r1);
                printf("\n");
                tMatrix r2 = TransposeMatrix(matrix2);
                MatrixPrint(r2);
                break;
            }
        }
        printf("\n");;
    }
    return 0;
}
void imprimeUI(){
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: \n");
}