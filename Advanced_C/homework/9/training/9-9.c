#include<stdio.h>

int * mid(int ar[]);

int main(){
	
	int ar[3];
	int *pa;
	
	for(pa=ar;pa<ar+3;pa++){
		scanf("%d",pa);
	}
	
	pa = mid(ar);
	
	printf("%d",*pa);
	return 0;
}

int * mid(int ar[]){
	if((*(ar+1)<=*ar&&*ar<=*(ar+2))||(*(ar+2)<=*ar&&*ar<=*(ar+1)))return ar;
	else if((*ar<=*(ar+1)&&*(ar+1)<=*(ar+2))||(*ar>=*(ar+1)&&*(ar+1)>=*(ar+2)))return ar+1;
	return ar+2;
}