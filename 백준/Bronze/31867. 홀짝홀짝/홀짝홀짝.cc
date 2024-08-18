#include<iostream>

using namespace std;

int main(){
    
    int N;
    string K;
    cin >> N >> K;
    
    int a =0 ,b = 0;
    for(int i=0;i<N;i++){
        if(K[i]%2==0)a++;
        else b++;
    }
    if(a>b)cout << 0 << "\n";
    else if(a<b)cout << 1 << "\n";
    else cout << -1;
    
    return 0;
}