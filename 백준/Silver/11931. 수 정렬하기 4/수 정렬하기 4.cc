#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    
    int arr[1000000];
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    
    sort(arr,arr+N);
    reverse(arr,arr+N);
    for(int i=0;i<N;i++){
        cout << arr[i] << "\n";
    }
    
    return 0;
}