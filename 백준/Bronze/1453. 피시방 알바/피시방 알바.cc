#include<iostream>
using namespace std;

int main(){
    
    int N;
    int arr[101] ={0,};
    
    cin >> N;
    
    int num;
    int ans = 0;
    for(int i=0;i<N;i++){
        cin >> num;
        if(arr[num]){
            ans++;
        }
        arr[num]=1;
    }
    cout << ans << "\n";
    
    return 0;
}