#include <stdio.h>
#include "utils.h"

int main()
{

    int tam = 0;

    scanf("%d",&tam);

    int *vet = CriaVetor(tam);
    LeVetor(vet,tam);

    float avg = CalculaMedia(vet,tam);

    LiberaVetor(vet);

    printf("%.2f",avg);
    
    return 0;
}