#include<iostream>

using namespace std;
int main(){
    
    int T;
    cin >> T;
    
    for(int t=0;t<T;t++){
        int a,b,c;
        int cnt = 0;
        cin >> a >> b >> c;
        
        if(a>=10)cnt++;
        if(b>=10)cnt++;
        if(c>=10)cnt++;
        
        cout << a << " " << b << " " << c << "\n";
        if(cnt==0)cout << "zilch";
        else if(cnt==1)cout << "double";
        else if(cnt==2)cout << "double-double";
        else if(cnt==3)cout << "triple-double";
        cout << "\n\n";
    }
    
    return 0;
}