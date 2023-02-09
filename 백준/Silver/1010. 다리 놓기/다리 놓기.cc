#include<iostream>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        int N,M;
        cin >> N >> M;
        
        //mCn -> M개 중에서 N개 선택
        long long cnt = 1;
        
        for(int i=1;i<=N;i++){
            cnt *= (M-i+1);
            cnt /= i;
        }
        
        cout << cnt << "\n";
        
    }
    
    
    return 0;
}