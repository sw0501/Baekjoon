#include <iostream>
#include <algorithm>

using namespace std;

int arr[5] = {0,};

int main() 
{
    // 코드를 작성해주세요
    
    for(int i=0;i<5;i++){
        cin >> arr[i];
    }
    
    sort(arr,arr+5);
    
    int cnt = 0;
    for(int i=3;i>=0;i--){
        if(arr[4] - arr[i] <= 1000)cnt++;
    }
    cout << cnt << "\n";
    
    return 0;
}
