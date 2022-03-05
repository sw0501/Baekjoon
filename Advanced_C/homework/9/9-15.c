#include<stdio.h>

void ABC(int *pS,int k);

int main(){
	
	int ar[10];
	int *p;
	
	for(p=ar;p<ar+10;p++){
		scanf("%d",p);
	}
	
	ABC(ar,10);
	
	for(p=ar;p<ar+10;p++){
		printf(" %d",*p);
	}
	
	return 0;
}

void ABC(int *pS,int k){
	int *p1,*p2;
	int M,idx;
	for(p1=pS;p1<pS+k;p1++){
		//첫번째 원소 제일 큰 값으로 두기
		M=*p1;
		idx = (int)(p1-pS);
		for(p2=p1;p2<pS+k;p2++){
			if(*p2>M){
				M=*p2;
				idx = (int)(p2-pS);
			}
		}
		int temp = *p1;
		*p1 = *(pS+idx);
		*(pS+idx)=temp;
	}
}