#include "utils.h"
#include <stdio.h>

int main()
{
    int l = 0, c = 0;

    scanf("%d %d",&l,&c);

    int **mat = CriaMatriz(l,c);

    LeMatriz(mat,l,c);
    ImprimeMatrizTransposta(mat,l,c);
    LiberaMatriz(mat,l);

    return 0;

}