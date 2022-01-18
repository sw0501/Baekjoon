#include <bits/stdc++.h>

using namespace std;

void init();
double ternary(double *lo,double *hi);

double AB[4];
double CD[4];

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	//각 위치별로 삼분탐색 진행
	
	for(int i=0;i<4;i++){
		cin >> AB[i];
	}
	for(int i=0;i<4;i++){
		cin >> CD[i];
	}
	
	cout.precision(10);
	cout << ternary(AB,CD) << "\n";
	
}

double ternary(double *lo,double *hi){
		
	//100번 정도 반복하면 근사값 구할 수 있음
	for(int i=0;i<100;i++){
		double Ax = (2*lo[0]+lo[2])/3;
		double Bx = (lo[0]+2*lo[2])/3;
		double Ay = (2*lo[1]+lo[3])/3;
		double By = (lo[1]+2*lo[3])/3;
		double Cx = (2*hi[0]+hi[2])/3;
		double Dx = (hi[0]+2*hi[2])/3;
		double Cy = (2*hi[1]+hi[3])/3;
		double Dy = (hi[1]+2*hi[3])/3;
		double mid1 = sqrt((Ax-Cx)*(Ax-Cx)+(Ay-Cy)*(Ay-Cy));
		double mid2 = sqrt((Bx-Dx)*(Bx-Dx)+(By-Dy)*(By-Dy));
		if(mid1<mid2){
			lo[2] = Bx;
			lo[3] = By;
			hi[2] = Dx;
			hi[3] = Dy;
		}
		else{
			lo[0] = Ax;
			lo[1] = Ay;
			hi[0] = Cx;
			hi[1] = Cy;
		}
	}
	
	double ABx = (lo[0]+lo[2])/2;
	double ABy = (lo[1]+lo[3])/2;
	double CDx = (hi[0]+hi[2])/2;
	double CDy = (hi[1]+hi[3])/2;
	
	double mid = sqrt((ABx-CDx)*(ABx-CDx)+(ABy-CDy)*(ABy-CDy));
	
	return mid;
}
