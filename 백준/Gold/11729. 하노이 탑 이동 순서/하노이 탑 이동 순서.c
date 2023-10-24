#include<stdio.h>

int N;
int try = 1;

int hanoi(int n,int a,int b){
    if(n==1)
    {
        printf("%d %d\n",a,b);
    }
    else 
    {
        hanoi(n-1,a,6-a-b);
        hanoi(1,a,b);
        hanoi(n-1,6-a-b,b);
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        try*=2;
    }
    try-=1;
    printf("%d\n",try);
    hanoi(N,1,3);
    
    
    return 0;
}