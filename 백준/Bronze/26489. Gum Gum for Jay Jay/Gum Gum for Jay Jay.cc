#include<iostream>

using namespace std;

int main(){
    
    string str;
    int n=0;
    while(getline(cin, str)){
        n++;
    }
    
    cout << n << "\n";
    
    return 0;
}