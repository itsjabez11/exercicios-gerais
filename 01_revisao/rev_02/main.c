#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int i,j,x = 1;
    for(i = 0; i<n; i++){
        for(j= 0;j<=i;j++){
            if(j<i){
                printf("%d ",x);
            }else{
                printf("%d\n",x);
            }
            x++;
        }
    }
    return 0;
}