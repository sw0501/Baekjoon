#include <bits/stdc++.h>
#include "List.h"
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
	int i=0;
	for(i=0;i<5;i++)
		addrear(i);
	printlist(pStart);
}
