#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        if(num==300)cout << 1 << " ";
        else if(num>=275)cout << 2 << " ";
        else if(num>=250)cout << 3 << " ";
        else cout << 4 << " ";
    }
    
    return 0;
}