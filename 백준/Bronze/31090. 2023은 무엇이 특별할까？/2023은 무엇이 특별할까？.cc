#include<iostream>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    for(int i=0;i<T;i++){
        int N;
        cin >> N;
        if((N+1)%(N%100)==0)cout << "Good" <<"\n";
        else cout << "Bye\n";
    }
    
    
    return 0;
}