#include<stdio.h>

int main(){
	
	int ar[28]={0,};
	char ch[10];
	int *pa = ar;
	char *pc = ch;
	
	char answer = ' ';
	int C = 0;
	
	scanf("%s",pc);
	
	for(pc=ch;pc<ch+10;pc++){
		int temp = (int)(*pc-'a');
		*(pa+temp) += 1;
	}
	
	for(pc=ch;pc<ch+10;pc++){
		int temp = (int)(*(pc)-'a');
		
		if(*(pa+temp)>C){
			answer = *pc;
			C = *(pa+temp);
		}
	}
	
	printf("%c %d\n",answer,C);
	
	return 0;
}