#include <stdio.h>
#include <math.h>

int DecimalToOctal(int n);

int main(){

    int dec;
    scanf("%d",&dec);

    int oct = DecimalToOctal(dec);
    printf("%d",oct);
    return 0;

}

int DecimalToOctal(int n){

    int resto = 0;
    int octal = 0;
    int quot = 0;
    int i = 0;
    while(1){
        resto = n%8;
        quot = n/8;
        n = quot;
        octal += resto*(pow(10,i));
        if(quot==0){
            return octal;
        }
        i++;
    }
}