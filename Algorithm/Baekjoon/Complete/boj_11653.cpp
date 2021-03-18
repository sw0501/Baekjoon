#include<iostream>
using namespace std;

int N;

void check(int n);

int main(){
    
    cin >> N;
    
    int i = 2;
    if(N!=1){
		check(N);
	}
    
    
    return 0;
}

void check(int n){
    for(int i=2;i*i<=n;){
        if(n%i==0){
			cout << i << "\n";
			n/=i;
		}
		else i++;
    }
	if(n!=1)cout << n << "\n";
}