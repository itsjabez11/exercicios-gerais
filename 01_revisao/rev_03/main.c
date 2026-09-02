#include <stdio.h>

int main(){
    int qtd;
    scanf("%d",&qtd);
    int i,j;
    int vet[qtd];
    int res[qtd];
    for(i = 0; i<qtd; i++){
        scanf("%d",&vet[i]);
    }
    int s_total = 0;
    int k = 0;
    for(i = 0; i<qtd; i++){
        int s= 0;
        for(j = 0; j<qtd; j++){
            if(i!=j && vet[i]==vet[j]){
                s++;
            }
        }
        if(s==0){
            res[k] = vet[i];
            s_total++;
            k++;
        }
    }
    int aux;
    for(i = 0; i<k-1;i++){
        for(j = 0; j<k-i-1;j++){
            if(res[j]>res[j+1]){
                aux = res[j];
                res[j] = res[j+1];
                res[j+1] = aux;
            }
        }
    }
    for(i = 0; i<k; i++){
        printf("%d ",res[i]);
    }
    if(!s_total){
        printf("NENHUM");
    }
    return 0;
}