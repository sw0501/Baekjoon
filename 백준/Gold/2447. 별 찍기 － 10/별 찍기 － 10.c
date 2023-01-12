#include <stdio.h>

int N; //총 개수
int T=0; //3의 거듭제곱
int line=0; //줄 개수
int flag=1; //공백 확인용

void star(int n,int m);
int involuton(int n);

int main()
{
    scanf("%d",&N);
    int temp = N;
    while(temp!=1){
        temp/=3;
        T++;
    }
    star(0,0);
    return 0;
}

void star(int n,int m){
    if(n<T){
        flag=1;
        int temp = involuton(n);
        if(((m/temp)+1)%3+3*(((line/temp))%3)==5){
            flag=0;
            printf(" ");
        }
        else star(n+1,m);
        if(n==0){
            if(flag)printf("*");
            if(m==N-1){
                line++;
                if(line<N){
                    printf("\n");
                    star(n,0);
                }
            }
            else star(n,m+1);
        }   
    }
}

int involuton(int n){
    int temp=1;
    for(int i=0;i<n;i++){
        temp*=3;
    }
    return temp;
}