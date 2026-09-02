#include <stdio.h>
#include "esfera_utils.h"

int main(){
    float r;
    scanf("%f",&r);

    float a = calcula_area(r);
    float v = calcula_volume(r);
    printf("Area: %.2f\n",a);
    printf("Volume: %.2f\n",v);
    return 0;
}