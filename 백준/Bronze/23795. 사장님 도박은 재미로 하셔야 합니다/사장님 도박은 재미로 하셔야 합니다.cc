#include<iostream>

using namespace std;

int main(){
    
    int sum=0;
    int temp;
    cin >> temp;
    while(temp!=-1){
        sum+=temp;
        cin >> temp;
    }
    
    cout << sum << "\n";
}