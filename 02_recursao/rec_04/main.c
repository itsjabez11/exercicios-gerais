#include <stdio.h>
#include <string.h>

int palindromo(char* string,int inicio,int tamanho);

int main(){
    char str[1000];
    while(scanf("%s",str)!=EOF){
        if(palindromo(str,0,strlen(str)-1)){
            printf("SIM\n");
        }else{
            printf("NAO\n");
        }
    }
}
int palindromo(char* string,int inicio,int tamanho){
    if(inicio>=tamanho){
        return 1;
    }
    if(string[inicio]!=string[tamanho]){
        return 0;
    }
    return palindromo(string,inicio+1,tamanho-1);
}