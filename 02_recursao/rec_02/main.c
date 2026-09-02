#include <stdio.h>

int SomaElementosPares(int* vet, int numElementos);

void leVetor();

int main(){
    int n;
    scanf("%d",&n);
    int i =0;
    for(i = 0; i<n; i++){
        leVetor();
    }
}
int SomaElementosPares(int* vet, int numElementos){
    if (numElementos<0){
        return 0;
    }
    if(vet[numElementos]%2==0){
        return vet[numElementos]+SomaElementosPares(vet,numElementos-1);
    }
    return SomaElementosPares(vet,numElementos-1);
}
void leVetor(){
    int qtd;
    scanf("%d",&qtd);
    int vet[qtd];
    int i = 0;
    for(i = 0; i<qtd; i++){
        scanf("%d",&vet[i]);
    }
    int s = SomaElementosPares(vet,qtd-1);
    printf("%d\n",s);
}