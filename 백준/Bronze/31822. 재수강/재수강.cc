#include<iostream>

using namespace std;

int main(){
    
    string str;
    cin >> str;
    
    int t;
    cin >> t;
    int cnt = 0;
    for(int i=0;i<t;i++){
        string temp;
        cin >> temp;
        int flag = 1;
        for(int j=0;j<5;j++){
            if(str[j]!=temp[j]){
                flag = 0;
                break;
            }
        }
        cnt+=flag;
    }
    cout << cnt << "\n";
    
    return 0;
}