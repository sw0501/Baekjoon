#include<iostream>

using namespace std;

int main(){
    
    long long N;
    cin >> N;
    cout << (int)(N*(1-0.22)) << " " << (int)(N*0.8 + N*0.2*(1-0.22));
    
    return 0;
}