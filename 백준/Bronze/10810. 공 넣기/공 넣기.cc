#include<iostream>

using namespace std;

int main(){
    
    int N, L;
    cin >> N >> L;
    int i,j,k;
    int arr[101] = {0,};
    for(int n=0;n<L;n++){
        cin >> i >> j >> k;
        
        if(i>j){
            int temp = j;
            j = i;
            i = temp;
        }
        for(int l = i-1;l<=j-1;l++){
            arr[l] = k;
        }
    }
    
    for(int n=0;n<N;n++){
        cout << arr[n] << " ";
    }
    return 0;
}