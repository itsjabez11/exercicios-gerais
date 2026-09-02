#include <stdio.h>
#include <string.h>

void ImprimeInvertido(char* string, int qtd);

int main(void){
    char str[1001];
    while(scanf("%s",str)==1){
        if(str[strlen(str)+2]=='\n'){
            break;
        }
        ImprimeInvertido(str,strlen(str));
    }
    
}
void ImprimeInvertido(char* string,int qtd){
    if(qtd<0){
        printf(" ");
        return;
    }
    printf("%c",string[qtd]);
    return ImprimeInvertido(string,qtd-1);
}