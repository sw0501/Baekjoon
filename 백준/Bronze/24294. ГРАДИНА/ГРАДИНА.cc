#include<iostream>
#include<cmath>

using namespace std;

int main(){
    
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    
    int width = max(a,c);
    int height = b + d;
    
    cout << height * 2 + width * 2 + 4;
    
    return 0;
}