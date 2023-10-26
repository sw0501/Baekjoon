#include<iostream>

using namespace std;

int main(){
    
    double A1,P1;
    double R1,P2;
    cin >> A1 >> P1 >> R1 >> P2;
    double pi = 3.14159265359;
    double a = (double)A1/P1;
    double b = (double)(R1*R1)*pi/P2;
    
    if(a>b)cout << "Slice of pizza";
    else cout << "Whole pizza";
    
    return 0;
}