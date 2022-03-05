#include<stdio.h>

int main(){
	
	int ar[50];
	int *p;
	int N,C=0;
	
	scanf("%d",&N);
	
	for(p=ar;p<ar+N;p++){
		scanf("%d",p);
		if(*p==0)printf("%d\n",C);
		C++;
	}
	
	return 0;
}