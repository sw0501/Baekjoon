#include<stdio.h>

int main(void) {

    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int x1,y1,r1,x2,y2,r2;
        scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
        if(r2>r1){
            int temp=x1; x1=x2; x2=temp;
            temp=y1; y1=y2; y2=temp;
            temp=r1; r1=r2; r2=temp;
        }
        int len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
        
        if(x1==x2&&y1==y2&&r1==r2)printf("-1\n");
        else if(len<(r1-r2)*(r1-r2)||(r1+r2)*(r1+r2)<len)printf("0\n");
        else if(len==(r1-r2)*(r1-r2)||len==(r1+r2)*(r1+r2))printf("1\n");
        else printf("2\n");
        
        
    }
    
	return 0;
}