#include<iostream>
#include<cmath>

using namespace std;

int main(){
    
    int A,B;
    cin >> A >> B;
    
    double M = (double)(B-A)/400;
    
    cout << 1/(1 + pow(10,M));
    
    return 0;
}