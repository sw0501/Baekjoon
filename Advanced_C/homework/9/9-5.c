#include<stdio.h>

int main(){
	
	int arr[5];
	int rank[5];
	int *p1;
	int *p2;
	
	for(p1=arr,p2=rank;p1<arr+5;p1++,p2++){
		scanf("%d",p1);
		*p2 = *p1;
	}
	
	for(p1=rank+4;p1>=rank;p1--){
		for(p2=rank;p2<p1;p2++){
			//작은 수 끝으로 옮김
			if(*p2<*(p2+1)){
				int tmp = *(p2+1);
				*(p2+1) = *p2;
				*p2 = tmp;
			}
		}
	}
	
	for(p1=rank;p1<rank+5;p1++){
		p2 = p1+1;
		while(*p1==*p2&&p2<rank+5){
			*p2=0;
			p2++;
		}
	}
	
	for(p1=arr;p1<arr+5;p1++){
		for(p2=rank;p2<rank+5;p2++){
			if(*p1==*p2)printf("%d=r%d ",*p1,(int)(p2-rank+1));
		}
	}
	printf("\n");
	
	return 0;
}