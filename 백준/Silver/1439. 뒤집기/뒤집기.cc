#include<iostream>

using namespace std;

int main(){
    
    string str;
    cin >> str;
    
    char c = str[0];
    int cnt1 = 0;
    int cnt2 = 0;
    
    if(str[0]=='0'){
        cnt1++;
    }
    else {
        cnt2++;
    }
    
    for(int i=0;i<str.length();i++){
        if(str[i]!=c){
            if(str[i]=='0'){
                cnt1++;
            }
            else if(str[i]=='1'){
                cnt2++;
            }
            
            c= str[i];
        }
    }

    
    cout << (cnt1>cnt2?cnt2:cnt1) <<"\n";
    
    return 0;
}