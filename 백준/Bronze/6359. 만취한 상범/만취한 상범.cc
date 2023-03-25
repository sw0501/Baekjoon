#include<iostream>

using namespace std;

int main(){
    
    int T;
    
    cin >> T;
    
    for(int t=0;t<T;t++){
        int N;
        cin >> N;
        
        int arr[101] = {0,};
        
        for(int i=2;i<=N;i++){
            for(int j=i;j<=N;j+=i){
                arr[j] = !arr[j];
            }
        }
        
        int ans = 0;
        for(int i=1;i<=N;i++){
            if(arr[i]==0){
                ans++;
            }
        }
        cout << ans << "\n";
    }
    
    
    
    return 0;
}