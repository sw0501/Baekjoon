#include<stdio.h>

int arrsum(int *pstart,int *pend);

int main(){
	
	int N,S,E;
	int ar[100];
	int *p;
	
	scanf("%d %d %d",&N,&S,&E);
	for(p=ar;p<ar+N;p++){
		scanf("%d",p);
	}
	p=ar;
	printf("%d",arrsum(p+S,p+E));
	
	return 0;
}

int arrsum(int *pstart,int *pend){
	int *p;
	int sum = 0;
	
	for(p=pstart;p<=pend;p++){
		sum += *p;
	}
	
	return sum;
}