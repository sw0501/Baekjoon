#include<stdio.h>

void gcdlcm(int a,int b,int *x,int *y);

int main(){
	
	int a,b,x,y;
	int *px=&x,*py=&y;
	
	scanf("%d %d",&a,&b);
	
	gcdlcm(a,b,px,py);
	
	printf("%d %d",*px,*py);
	
	
	return 0;
}

void gcdlcm(int a,int b,int *x,int *y){
	
	//유클리드 호재법
	//X % Y = R 일때 X와 Y의 최대공약수는 Y와 R의 최대공약수와 같다.
	
	int A = a;
	int B = b;
	int R = 0;
	
	while(A%B){
		R = A % B;
		A = B;
		B = R;
	}
	
	*x = B;
	*y = a*b/B;

}