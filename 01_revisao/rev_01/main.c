#include <stdio.h>
#include <math.h>


typedef struct{
    float x,y,r;
}tCoord;


tCoord LeCoord();

float calculaDist(tCoord alvo, tCoord tiro);

int main(){
    tCoord alvo;
    tCoord tiro;
    alvo = LeCoord();
    tiro = LeCoord();
    float dist = calculaDist(alvo,tiro);
    
    if(alvo.r>=(dist-tiro.r)){
        printf("ACERTOU");
    }else{
        printf("ERROU");
    }
    return 0;
}
tCoord LeCoord(){
    tCoord x;
    scanf("%f %f %f",&x.x,&x.y,&x.r);
    return x;
}
float calculaDist(tCoord alvo, tCoord tiro){
    float dist = 0;
    dist = sqrt(pow(alvo.x-tiro.x,2)+pow(alvo.y-tiro.y,2));
    return dist;
}