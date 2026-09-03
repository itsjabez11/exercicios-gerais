#include "string_utils.h"
#include <string.h>

/**
 * @brief Retorna o tamanho de uma string.
 * @param str A string para obter o tamanho.
 * @return O tamanho da string.
 */
int string_length(char *str){
    
    return strlen(str);
}

/**
 * @brief Copia uma string de origem para destino.
 * @param src A string de origem.
 * @param dest A string de destino.
 */
void string_copy(char *src, char *dest){
    
    strcpy(dest,src);

}

/**
 * @brief Converte todos os caracteres de uma string para maiúsculas.
 * @param str A string para converter.
 */
void string_upper(char *str){
    int i = 0;
    int tam = string_length(str);
    for(i = 0; i<tam;i++){
        if(str[i]>='a' && str[i]<='z'){
            str[i]-=32;
        }
    }
}

/**
 * @brief Converte todos os caracteres de uma string para minúsculas.
 * @param str A string para converter.
 */
void string_lower(char *str){
    int i = 0;
    int tam = string_length(str);
    for(i = 0; i<tam;i++){
        if(str[i]>='A' && str[i]<='Z'){
            str[i]+=32;
        }
    }
}

/**
 * @brief Inverte uma string.
 * @param str A string para inverter.
 */
void string_reverse(char *str){
    int i = 0;
    int j = string_length(str)-1;
    char aux;
    for(i = 0; i<j ;i++){
        aux = str[i];
        str[i] = str[j];
        str[j] = aux;
        j--;
    }
}

