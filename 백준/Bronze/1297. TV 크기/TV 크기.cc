#include <bits/stdc++.h>

using namespace std;

void init();

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int D,H,W;
	
	cin >> D >> H >> W;
	
	double x = ((double)(D*D)/(double)(H*H+W*W));
	x = sqrt(x);
	cout << (int)(H*x) << " " << (int)(W*x); 
	return 0;
	
}

