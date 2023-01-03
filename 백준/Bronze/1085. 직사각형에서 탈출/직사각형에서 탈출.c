#include<stdio.h>

int main(){
    
    int x,y,w,h;
    scanf("%d %d %d %d",&x,&y,&w,&h);
    int x1,y1;
    if(x>w/2)x1 = w-x;
    else x1 = x;
    if(y>h/2)y1 = h-y;
    else y1 = y;
    if(x1>y1)printf("%d",y1);
    else printf("%d",x1);
    
    
    
    return 0;
}