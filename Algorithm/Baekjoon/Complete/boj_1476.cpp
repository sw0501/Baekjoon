#include<iostream>
#include<set>

using namespace std;

int E;
int S;
int M;

int main(){
	
	cin >> E >> S >> M;
	
	int e=1,s=1,m=1;
	int c = 1;
	while(!(e==E&&s==S&&m==M)){
		c++;
		e++;
		s++;
		m++;
		if(e>15)e=1;
		if(s>28)s=1;
		if(m>19)m=1;
	}
	cout << c;
}