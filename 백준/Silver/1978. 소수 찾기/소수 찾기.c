#include<stdio.h>

int main(){
    
    int t;
    int n=0;
    scanf("%d",&t);
    
    for(int i=0;i<t;i++){
        int x;
        int y=1;
        scanf("%d",&x);
        if(x>2){
            for(int j=2;j<x;j++){
                if(x%j==0){
                    y=0;
                    break;
                }
            }
        }
        else if(x==1)y=0;
        if(y)n++;
    }
    printf("%d",n);
    return 0;
}