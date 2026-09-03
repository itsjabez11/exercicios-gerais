#include <stdio.h>
#include "string_utils.h"
#include <string.h>


void imprimeUI();

int main(){
    char str[1000];
    scanf("%[^\n]",str);
    
    int choose = 0;
    

    while(choose!=6){
        imprimeUI();
        scanf("%d",&choose);
        switch (choose){
            case 1:{
                printf("Tamanho da string: %d\n",string_length(str));
                printf("\n");
                break;
            }
            case 2:{
                char dest[string_length(str)];
                string_copy(str,dest);
                printf("String copiada: %s\n",dest);
                printf("\n");
                break;
            }
            case 3:{
                string_upper(str);
                printf("String convertida para maiusculas: %s\n",str);
                printf("\n");
                break;
            }
            case 4:{
                string_lower(str);
                printf("String convertida para minusculas: %s\n",str);
                printf("\n");
                break;
            }
            case 5:{
                string_reverse(str);
                printf("String invertida: %s\n",str);
                printf("\n");
                break;
            }
        }
         
    }
    return 0;
}

void imprimeUI(){
    printf("1 - Tamanho da string\n");
    printf("2 - Copiar string\n");
    printf("3 - Converter string para letras maiusculas\n");
    printf("4 - Converter string para letras minusculas\n");
    printf("5 - Imprimir string ao contrario\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: ");
    printf("\n");
}