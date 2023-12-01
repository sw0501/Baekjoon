#include<iostream>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    for(int i=0;i<T;i++){
        int num;
        cin >> num;
        
        if(num%2==0)
            cout << num << " is even\n";
        else
            cout << num << " is odd\n";
    }
    
    return 0;
}