#include<iostream>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        
        cout << a << " " << b << "\n";
        cout << b * a - 2 * (a-1) << "\n";
    }
    
    return 0;
}