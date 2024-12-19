#include<iostream>

using namespace std;

int num[1001] = {0,};

int main(){
    
    int N,M;
    cin >> N >> M;
    
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        num[a]++;
        num[b]++;
    }
    
    for(int i=1;i<=N;i++){
        cout << num[i] << "\n";
    }
    
    return 0;
}