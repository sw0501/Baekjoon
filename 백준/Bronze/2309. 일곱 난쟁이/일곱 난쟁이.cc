#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    
    int arr[9];
    int arr2[7];
    int sum = 0;
    
    for(int i=0;i<9;i++){
        cin >>arr[i];
        sum += arr[i];
    }
    
    for(int i=0;i<9;i++){
        for(int j=i+1;j<9;j++){
            if(sum - (arr[i]+arr[j]) == 100){
                int n=0;
                for(int k=0;k<9;k++){
                    if(k!=i&&k!=j){
                        arr2[n++] = arr[k];
                    }
                }
            }
        }
    }
    
    sort(arr2,arr2+7);
    
    for(int i=0;i<7;i++){
        cout << arr2[i] << "\n";
    }
    
    return 0;
}