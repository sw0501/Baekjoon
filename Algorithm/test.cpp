#include <bits/stdc++.h>
using namespace std;

void init();

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){ 
	int a[5] = {4,5,6,7,8};
	int b[5] = {1,3,5,7,9};
	int c[5] = {0,2,4,6,8};
	int *p[3];
	p[0] = a;
	p[1] = b;
	p[2] = c;
	for(int i=0;i<3;i++){
		for(int j=0;j<5;j++){
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}
}
