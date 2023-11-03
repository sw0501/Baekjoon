#include<iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    
    for(int t=0;t<T;t++){
        int c;
        cin >> c;
        
        for(int i=0;i<c;i++){
            int a,b;
            cin >> a >> b;
            cout << a + b << " " << a * b << "\n";
        }
    }
    
}