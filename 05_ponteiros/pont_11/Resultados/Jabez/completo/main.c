#include "calculadora.h"
#include <stdio.h>


float a(float n1, float n2);

float s(float n1, float n2);

float m(float n1, float n2);

float d(float n1, float n2);


int main()
{

    char operation  = '\0';
    
    while(operation!='f'){

        scanf(" %c",&operation);

        if(operation == 'f'){
            break;
        }
        float res = 0;

        float n1,n2;

        scanf("%f %f",&n1,&n2);

        CalculatoraCallback op;

        if(operation == 'a'){

            op = a;

        }else if(operation == 's'){

            op = s;

        }else if(operation == 'm'){

            op = m;
            
        }else if(operation == 'd'){

            op = d;
            
        }
        res = Calcular(n1,n2,op);
        printf("%.2f\n",res);
    }

    return 0;
}

float a(float n1, float n2){

    printf("%.2f + %.2f = ", n1, n2);
    return n1+n2;

}

float s(float n1, float n2){

    printf("%.2f - %.2f = ", n1, n2);
    return n1-n2;

}

float m(float n1, float n2){

    printf("%.2f x %.2f = ", n1, n2);
    return n1*n2;

}

float d(float n1, float n2){

    printf("%.2f / %.2f = ", n1, n2);
    return n1/n2;
    
}
