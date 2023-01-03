#include<stdio.h>

int main(void) {

    int N,M;
    scanf("%d %d",&N,&M);
    getchar();
    char r[50][50];
    int draw_rect;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%c",&r[i][j]);
        }
        getchar();
    }
    for(int i=0;i<=N-8;i++){
        for(int j=0;j<=M-8;j++){
            int temp=0;
            char f = r[i][j];
            for(int k=0;k<8;k++){
                for(int l=0;l<8;l++){
                   if((i+k+j+l)%2==(i+j)%2){
                       if(f!=r[i+k][j+l])temp++;
                   }
                   else {
                       if(f==r[i+k][j+l])temp++;
                   }
                }
            }
            if(temp>64-temp)temp = 64-temp;
            if(i==0&&j==0)draw_rect=temp;
            else if(draw_rect>temp)draw_rect=temp;
        }
    }
    printf("%d",draw_rect);
    
    
    
	return 0;
}