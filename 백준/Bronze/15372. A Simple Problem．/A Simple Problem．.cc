#include<iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    
    for(int i=0;i<T;i++){
        long long N;
        cin >> N;
        cout << N*N << "\n";
    }
    
    
}