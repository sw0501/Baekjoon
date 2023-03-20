#include<iostream>

using namespace std;

int main(){
    
    int arr[101] = {0,};
    
    int N,M;
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        arr[i] = i;
    }
    
    int a,b;
    for(int i=0;i<M;i++){
        cin >> a >> b;
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    
    for(int i=1;i<=N;i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}