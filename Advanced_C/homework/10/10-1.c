#include<stdio.h>
#include<stdlib.h>

int main(){

    char str[21];
	gets(str);
	for(int i=0;i<21;i++){
		if(str[i]=='\0')break;
		
		if(str[i]>='a'&&str[i]<='z')printf("%c",str[i]);
	}
	
	

	return 0;
}