#include<stdio.h>

int main(){
	
	int x,y,z;
	int *px,*py,*pz,*tmp;	//tmp는 포인터이다
	
	//1) 
	px = &x;
	py = &y;
	pz = &z;
	tmp = NULL;
	scanf("%d %d %d",px,py,pz);
	
	//2)
	tmp = pz;
	pz = py;
	py = px;
	px = tmp;
	
	//3)
	printf("%d %d %d",*px,*py,*pz);
	
	
	return 0;
}