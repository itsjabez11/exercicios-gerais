#include "utils_char.h"
#include <stdio.h>

int main()
{
    int qtd = 0;

    scanf("%d ",&qtd);
    
    char *txt = CriaVetor(qtd);
    ImprimeString(txt,qtd);
    LeVetor(txt,qtd);
    ImprimeString(txt,qtd);

    LiberaVetor(txt);

    return 0;
}