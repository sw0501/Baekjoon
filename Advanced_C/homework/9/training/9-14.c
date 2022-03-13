#include<stdio.h>

int add_to_k(int *s,int *e);

int main(){
	
	int N;
	int d[100];
	int *p;
	
	scanf("%d",&N);
	for(p=d;p<d+N;p++){
		scanf("%d",p);
	}
	
	p=d;
	printf("%d\n",add_to_k(p,p+N-1));
	
	return 0;
}

int add_to_k(int *s,int *e){
	int *p;
	int sum=0;
	
	//0번째 index = N번
	//1번째 index = N-1번 더해진다
	for(p=s;p<=e;p++){
		sum += *p*(int)(e-p+1);
	}
	return sum;
}