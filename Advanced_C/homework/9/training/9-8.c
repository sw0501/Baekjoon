#include<stdio.h>

void swap(int *x,int *y);

int main( ){
	
	int N;
	int ar[50];
	int a,b;
	int *p;
	
	scanf("%d",&N);
	
	for(p=ar;p<ar+N;p++){
		scanf("%d",p);
	}
	
	scanf("%d %d",&a,&b);
	
	p = ar;
	
	swap(p+a,p+b);
	
	for(p=ar;p<ar+N;p++){
		printf(" %d",*p);
	}
	
	return 0;
}

void swap(int *x,int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

