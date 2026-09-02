#include <stdio.h>

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado);

void leCaso();

int main(){
    int n,i;
    scanf("%d",&n);
    for(i = 0; i<n; i++){
        leCaso();
    }
    return 0;
}
void leCaso(){
    int x,i;
    scanf("%d",&x);
    int qtd;
    scanf("%d",&qtd);
    int vet[qtd];
    for(i = 0; i<qtd; i++){
        scanf("%d",&vet[i]);
    }
    printf("%d\n",ContaOcorrencias(vet,qtd,x));
}
int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado){
    if(numElementos<0){
        return 0;
    }
    if(vet[numElementos]==numeroProcurado){
        return ContaOcorrencias(vet,numElementos-1,numeroProcurado)+1;
    }
    return ContaOcorrencias(vet,numElementos-1,numeroProcurado);
}