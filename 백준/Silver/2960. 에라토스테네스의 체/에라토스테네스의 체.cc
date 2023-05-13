#include<iostream>

using namespace std;

int main(){
    
    int N,K;
    int arr[1001] = {0,};
    cin >> N >> K;
    
    int k = 0;
    for(int i=2;i<=N;i++){
        if(arr[i]==0){
            for(int j=i;j<=N;j+=i){
                if(arr[j]==0){
                    arr[j] = 1;
                    k++;
                    if(k==K)cout << j << "\n";
                }
            }
        }
    }
    
    return 0;
}