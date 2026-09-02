#include <stdio.h>
#include <string.h>


int main(){
    int lim;
    scanf("%d",&lim);

    int i = 0;

    char str[1001];
    int cont[256] = {0};

    scanf("%s",str);

    for(i = 0;str[i]!='\0';i++){
        if((str[i]>='a' && str[i]<='z')||(str[i]>='A' && str[i]<='Z')||(str[i]>='0' && str[i]<='9')){
            cont[str[i]]++;
        }
    }
    int encontrou = 0;
    for(i = 0; i<256; i++){
        if(cont[i]>lim){
            printf("%c: %d\n",i,cont[i]);
            encontrou = 1;
        }
    }
    if(!encontrou){
        printf("NENHUM\n");
    }   
}

