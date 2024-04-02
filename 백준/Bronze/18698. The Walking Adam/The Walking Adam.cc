#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        string str;
        cin >> str;
        
        int cnt = 0;
        for(int j=0;j<str.length();j++){
            if(str[j]=='U')cnt++;
            else break;
        }
        cout << cnt << "\n";
    }
    
    return 0;
}