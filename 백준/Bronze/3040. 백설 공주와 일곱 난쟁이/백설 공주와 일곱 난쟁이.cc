#include<iostream>

using namespace std;

int main(){
    
    int total = 0;
    
    int arr[9];
    
    for(int i=0;i<9;i++){
        cin >> arr[i];
        total += arr[i];
    }
    
    for(int i=0;i<9;i++){
        for(int j=i+1;j<9;j++){
            if(total - arr[i] - arr[j] == 100){
                for(int k=0;k<9;k++){
                    if(k==i||k==j)continue;
                    cout << arr[k] << " ";
                }
                return 0;
            }
        }
    }
    
    return 0;
}