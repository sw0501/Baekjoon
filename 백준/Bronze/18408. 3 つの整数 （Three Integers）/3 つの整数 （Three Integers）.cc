#include<iostream>

using namespace std;

int main(){
    
    int arr[3] = {0,};
    
    int num;
    cin >> num;
    arr[num]++;
    cin >> num;
    arr[num]++;
    cin >> num;
    arr[num]++;
    
    if(arr[1]>arr[2]){
        cout << 1;
    }
    else{
        cout << 2;
    }
    return 0;
}