#include<iostream>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    int point = 0;
    int temp = 0;
    int num = 0;
    for(int i=0;i<n;i++){
        cin >> num;
        if(num){
            temp++;
            point += temp;
        }
        else{
            temp =0;
        }
    }
    //point += temp;
    
    cout << point << "\n";
    
    return 0;
}