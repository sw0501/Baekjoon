#include<iostream>

using namespace std;

int main(){
    
    int L,R;
    int M,S,G;
    double A,B;
    
    cin >> M >> S >> G;
    cin >> A >> B;
    cin >> L >> R;
    
    double t1 = L / A;
    double t2 = R / B;
    
    int m1 = M / G + 1;
    int m2 = M / S + 1;
    
    if(m1 + t1 < m2 + t2){
        cout << "friskus";
    }
    else{
        cout << "latmask";
    }
    
    return 0;
}