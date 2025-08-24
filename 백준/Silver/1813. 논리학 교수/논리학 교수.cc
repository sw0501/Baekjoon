#include<iostream>

using namespace std;

int main(){
    
    int cnt[51]=  {0,};
    
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        
        cnt[num]++;
    }
    
    int ans = -1;
    
    for(int i=50;i>=0;i--){
        if(cnt[i] == i){
            ans = i;
            break;
        }
    }
    
    if(ans == -1 && cnt[0] == 0){
        ans = 0;
    }
    
    cout << ans << "\n";
    
    
    
    return 0;
}