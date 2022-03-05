#include<stdio.h>

void addArray(int *a,int *b,int *c,int N);

int main(){
	
	int N;
	int a[20],b[20],c[20];
	int *p;
	scanf("%d",&N);
	for(p=a;p<a+N;p++){
		scanf("%d",p);
	}
	for(p=b;p<b+N;p++){
		scanf("%d",p);
	}
	
	addArray(a,b,c,N);
	
	for(p=c;p<c+N;p++){
		printf(" %d",*p);
	}
	return 0;
}

void addArray(int *a,int *b,int *c,int N){
	int *pa,*pb,*pc;
	for(pa=a,pb=b+N-1,pc=c;pa<a+N&&pb>=b;pa++,pb--,pc++){
		*pc = *pa+*pb;
	}
}