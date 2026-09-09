#include "matrix_utils.h"
#include <stdio.h>


/**
 * @brief Cria uma matriz com o número de linhas e colunas especificado.
 * @param rows O número de linhas na matriz.
 * @param cols O número de colunas na matriz.
 * @return A matriz criada.
 */
tMatrix MatrixCreate(int rows, int cols){
    tMatrix m;
    m.rows = rows;
    m.cols = cols;

    return m;

}

/**
 * @brief Lê uma matriz da entrada padrão.
 * @param matrix A matriz a ser lida.
 * @return A matriz lida.
 */
tMatrix MatrixRead(tMatrix matrix){

    int i,j;
    for(i = 0; i< matrix.rows; i++){
        for(j = 0; j<matrix.cols; j++){
            scanf("%d ",&matrix.data[i][j]);
        }
    }
    return matrix;
}

/**
 * @brief Imprime uma matriz na saída padrão.
 * @param matrix A matriz a ser impressa.
 */
void MatrixPrint(tMatrix matrix){

    int i,j;
    for(i = 0; i< matrix.rows; i++){
        printf("|");
        for(j = 0; j<matrix.cols; j++){
            if(j<matrix.cols-1){
                printf("%d ",matrix.data[i][j]);
            }else{
                printf("%d|\n",matrix.data[i][j]);
            }
            
        }
    }

}

/**
 * @brief Verifica se é possível somar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível somar as matrizes, 0 caso contrário.
 */
int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2){

    return matrix1.rows==matrix2.rows && matrix1.cols==matrix2.cols;
}

/**
 * @brief Verifica se é possível subtrair duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível subtrair as matrizes, 0 caso contrário.
 */
int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2){

    return matrix1.rows==matrix2.rows && matrix1.cols==matrix2.cols;

}

/**
 * @brief Verifica se é possível multiplicar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível multiplicar as matrizes, 0 caso contrário.
 */
int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2){

    return matrix1.cols==matrix2.rows;
}

/**
 * @brief Soma duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da soma.
 */
tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2){
    int i,j;
    tMatrix r;
    r.rows = matrix1.rows;
    r.cols = matrix1.cols;
    for(i = 0; i<matrix1.rows; i++){
        for(j = 0; j<matrix1.cols; j++){
            r.data[i][j] = 0;
        }
    }
    for(i = 0; i< matrix1.rows; i++){
        
        for(j = 0; j< matrix1.cols; j++){
            r.data[i][j] = matrix1.data[i][j]+matrix2.data[i][j];
        }
    }
    return r;
}

/**
 * @brief Subtrai duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da subtração.
 */
tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2){

    int i,j;
    tMatrix r;
    r.rows = matrix1.rows;
    r.cols = matrix1.cols;
    for(i = 0; i<matrix1.rows; i++){
        for(j = 0; j<matrix1.cols; j++){
            r.data[i][j] = 0;
        }
    }
    for(i = 0; i< matrix1.rows; i++){
        
        for(j = 0; j< matrix1.cols; j++){
            r.data[i][j] = matrix1.data[i][j]-matrix2.data[i][j];
        }
    }
    return r;

}

/**
 * @brief Multiplica duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da multiplicação.
 */
tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2){

    tMatrix r;
    r.rows = matrix1.rows;
    r.cols = matrix2.cols;
    int i,j,k;
    for(i = 0; i<matrix1.rows; i++){
        for(j = 0; j<matrix2.cols; j++){
            r.data[i][j] = 0;
        }
    }
    
    for(i = 0; i< matrix1.rows; i++){
        
        for(j = 0; j< matrix2.cols; j++){

            for(k = 0; k< matrix1.cols; k++){

                r.data[i][j] +=matrix1.data[i][k]*matrix2.data[k][j];
            }
        }
    }
    return r;
}

/**
 * @brief Transpõe uma matriz.
 * @param matrix A matriz a ser transposta.
 * @return A matriz transposta.
 */
tMatrix TransposeMatrix(tMatrix matrix){

    tMatrix r;
    r.rows = matrix.cols;
    r.cols = matrix.rows;
    int i,j;
    for(i = 0; i< matrix.cols ; i++){
        for(j = 0; j<matrix.rows; j++){
            r.data[i][j] = matrix.data[j][i];
        }
    }
    return r;
}

/**
 * @brief Multiplica uma matriz por um escalar.
 * @param matrix A matriz a ser multiplicada.
 * @param scalar O escalar pelo qual a matriz será multiplicada.
 * @return O resultado da multiplicação.
 */
tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar){
    int i,j;
    for(i = 0; i< matrix.rows; i++){
        for(j = 0; j<matrix.cols; j++){
            matrix.data[i][j]*=scalar;
        }
    }
    return matrix;
}

