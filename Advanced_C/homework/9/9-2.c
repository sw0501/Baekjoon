#include<stdio.h>

int main(){
	
	char ch[20];
	char *pc = ch;
	int idx = 0;
	int i = 0;
	
	do{
		scanf("%c",pc++);
	}while(*(pc-1)!='\n');
		
	for(pc=ch;pc<ch+20;pc++){
		if(*(pc)=='#'){
			idx = pc-ch-1;
			break;
		}
	}
	
	for(pc=ch+idx;pc>=ch;pc--){
		printf("%c",*(pc));
	}
	
	return 0;
}