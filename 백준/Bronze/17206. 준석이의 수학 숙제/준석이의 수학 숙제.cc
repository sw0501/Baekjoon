#include <iostream>

using namespace std;

int arr[100001] = {0,};

int main() 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    // 코드를 작성해주세요
    for(int i=1;i<=100000;i++){
        arr[i] = arr[i-1];
        if(i%3 ==0 || i%7==0){
            arr[i] += i;
        }
    }
    
    int T;
    cin >> T;
    
    for(int i=0;i<T;i++){
        int num;
        cin >> num;
        
        cout << arr[num] << "\n";
    }
    
    return 0;
}
