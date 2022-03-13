#include <stdio.h>
#pragma warning(disalbe 4996)

void input(int ar[],int N);
int *diff(int ar[],int N);

int main(void) {
	
	int N;
	int ar[100];
	
	scanf("%d",&N);
	input(ar,N);
	
	return 0;
}

void input(int ar[],int N){
	int *p;
	for(p=ar;p<ar+N;p++){
		scanf("%d",p);
	}
	p = diff(ar,N);
	printf("%d %d",*(p-1),*p);
}

int *diff(int ar[],int N){
	int *p,dif=0,temp=0,*idx=ar;
	for(p=ar+1;p<ar+N;p++){
		temp = (*p-*(p-1)>0?*p-*(p-1):-(*p-*(p-1)));
		if(temp>dif){
			dif = temp;
			idx = p;
		}
	}
	return idx;
}
