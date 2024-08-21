#include<iostream>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    for(int t=0;t<T;t++){
        int a,b;
        cin >> a >> b;
        for(int i=0;i<b;i++){
            for(int j=0;j<a;j++){
                cout << "X";
            }
            cout << "\n";
        }
        if(t!=T-1){
            cout << "\n";
        }
    }
    
    return 0;
}