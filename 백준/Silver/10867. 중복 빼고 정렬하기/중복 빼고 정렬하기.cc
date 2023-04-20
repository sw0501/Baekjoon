#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int arr[100001] = {0,};
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    
    sort(arr,arr+N);
    
    int num = -1001;
    for(int i=0;i<N;i++){
        if(num!=arr[i]){
            num = arr[i];
            cout << arr[i] << " ";
        }
    }
    
    return 0;
}