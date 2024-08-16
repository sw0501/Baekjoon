#include<iostream>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    for(int t=0;t<n;t++){
        int i,f;
        cin >> i >> f;
        if((i<=1 && f<=2) || (i<=2 && f<=1)){
            cout << "Yes\n";
        }
        else{
            cout <<"No\n";
        }
    }
    
    return 0;
}