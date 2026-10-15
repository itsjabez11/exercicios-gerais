#include "utils_char2.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    char* vet;

    int tam = 0;

    vet = CriaVetorTamPadrao();
    vet = LeVetor(vet,&tam);

    ImprimeString(vet);

    LiberaVetor(vet);

    return 0;

}