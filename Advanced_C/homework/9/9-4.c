#include<stdio.h>

int main(){
	
	int ar[3];
	int *p1;
	int *p2;
	
	for(p1=ar;p1<ar+3;p1++){
		scanf("%d",p1);
	}
	
	for(p1=ar+2;p1>=ar;p1--){
		for(p2=ar;p2<p1;p2++){
			if(*(p2)<*(p2+1)){
				int tmp = *(p2+1);
				*(p2+1) = *p2;
				*p2 = tmp;
			}
		}
	}

	p1 = ar+1;
	printf("%d\n",*p1);
	
	return 0;
}