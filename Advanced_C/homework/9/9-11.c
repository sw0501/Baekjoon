#include<stdio.h>

void strcopy(char *a,char *b);

int main(){
	
	char a[6];
	char b[6];
	char *pa,*pb;
	
	for(pa = a;pa<a+6;pa++){
		scanf("%c",pa);
	}
	
	strcopy(a,b);
	
	for(pb = b;pb<b+6;pb++){
		printf("%c",*pb);
	}
	printf("\n");
	
	return 0;
}

void strcopy(char *a,char *b){
	
	char *pa = a;
	char *pb = b;
	
	for(pa=a,pb=b;pa<a+6;pa++,pb++){
		*pb = *pa;
	}
	
}