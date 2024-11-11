#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int arr[10000001] ={0,};

int main() 
{
    // 코드를 작성해주세요
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    
    sort(arr,arr+N);
    reverse(arr,arr+N);
    
    for(int i=0;i<N-2;i++){
        if(arr[i] < arr[i+1] + arr[i+2] ){
            cout << arr[i] + arr[i+1] + arr[i+2] << "\n";
            return 0;
        }
    }
    
    cout << -1 << "\n";
    
    return 0;
}
