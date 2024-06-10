#include<iostream>

using namespace std;

int main(){
    
    
    int N;
    
    cin >> N;
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        for(int j=1;j<=50;j++){
            if(j!=a+b){
                cout << j << "\n";
                break;
            }
        }
    }
    
    return 0;
}