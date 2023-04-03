#include<iostream>

using namespace std;

int main(){
    
    int arr[21] = {0,};
    for(int i=1;i<=20;i++){
        arr[i] = i;
    }
    int a,b;
    for(int i=0;i<10;i++){
        cin >> a >> b;
        int temp = 0;
        while(b>a){
            temp = arr[b];
            arr[b] = arr[a];
            arr[a] = temp;
            b--;
            a++;
        }
    }
    
    for(int i=1;i<=20;i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}