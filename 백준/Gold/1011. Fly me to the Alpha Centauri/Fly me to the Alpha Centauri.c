#include<stdio.h>

int main(){
    
    int t;
    scanf("%d",&t);
    
    for(int i=0;i<t;i++){
        int n=0;
        int x,y;
        scanf("%d %d",&x,&y);
        int distance=y-x;
        int m= 1;
        while(1){
            distance-=m;
            n++;
            if(n%2==0){
                m++;
            }
            if(distance<=0)break;
        }
        printf("%d\n",n);
    }
    /*
       distance : 1, 2, 3~4, 5~6, 7~9, 10~12, 13~16 
       rule     : 1, 1, 2 2, 3 3, 4 4, 5 5
       number   : 1  2  3 4  5 6  7 8  9 10
    */
   
    return 0;
}