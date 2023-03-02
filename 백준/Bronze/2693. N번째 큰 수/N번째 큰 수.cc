#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    
    int T;
    int arr[10];
    
    cin >> T;
    
    for(int t=0;t<T;t++){
        for(int i=0;i<10;i++){
            cin >> arr[i];
        }    
        sort(arr,arr+10);
        reverse(arr,arr+10);
        cout << arr[2] << "\n";
    }
    
    
    
    
    return 0;
}