#include <stdio.h>

typedef struct{
    int m;
    int n;
    int mat[20][20];
}tMatriz;

typedef struct{
    int xa, ya, xf, yf;
    char mov[4];
}tPlayer;

tMatriz LeMatriz();

tPlayer LePlayer();

void GameMovement(tMatriz mat, tPlayer p1);

int main(){
    tMatriz mat = LeMatriz();

    tPlayer player = LePlayer();

    GameMovement(mat,player);
    return 0;
}
tMatriz LeMatriz(){

    tMatriz mat;
    scanf("%d %d",&mat.m,&mat.n);
    int i = 0, j = 0;
    for(i = 0; i<mat.m; i++){
        for(j = 0; j<mat.n; j++){
            scanf("%d",&mat.mat[i][j]);
        }
    }
    return mat;
}
tPlayer LePlayer(){
    tPlayer player;
    scanf("%d %d ",&player.ya, &player.xa);
    scanf("%d %d ",&player.yf, &player.xf);
    int i = 0;

    for(i = 0; i<4; i++){
        scanf(" %c",&player.mov[i]);
    }
    
    return player;
}
void GameMovement(tMatriz mat, tPlayer p1){

    mat.mat[p1.ya-1][p1.xa-1] = 1;
    printf("(%d,%d) ",p1.ya,p1.xa);

    int moveu = 0;
    int i = 0;
    while(1){
        if(p1.ya ==p1.yf && p1.xa == p1.xf){
            break;
        }
        moveu = 0;
        for (i =0 ; i<4; i++){
            int ny = p1.ya;
            int nx = p1.xa;

            if(p1.mov[i]=='B'){
                    ny++;
                    
                
            }else if(p1.mov[i]=='D'){
                
                    nx++;
                    
                
            }else if(p1.mov[i]=='E'){
                
                    nx--;
                    
                
            }else if(p1.mov[i]=='C'){
                
                    ny--;
                    
                
            }
            if(ny>=1 && ny<=mat.m && nx>=1 && nx<=mat.n){
                if(mat.mat[ny-1][nx-1]==0){
                    p1.ya = ny;
                    p1.xa = nx;
                    mat.mat[p1.ya-1][p1.xa-1] =1 ;
                    printf("(%d,%d) ",p1.ya,p1.xa);
                    moveu = 1;
                    break;
                }
            }
        }
        if(!moveu){
           break; 
        }
    }
}