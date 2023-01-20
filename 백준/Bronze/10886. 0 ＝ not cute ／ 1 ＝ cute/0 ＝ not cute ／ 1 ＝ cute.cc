#include<iostream>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    int ans = 0;
    
    int tmp;
    for(int i=0;i<n;i++){
        cin >> tmp;
        if(tmp==1)ans++;
        else ans--;
    }
    if(ans>0){
        cout << "Junhee is cute!" << "\n";
    }
    else cout << "Junhee is not cute!" << "\n";
    
    
    return 0;
}