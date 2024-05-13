#include<iostream>

using namespace std;

int main(){
    
    
    string str;
    string ans;
    getline(cin,str);
    getline(cin,ans);
    
    int cnt = 0;
    for(int i=0;i<str.length();i++){
        if(str[i]==ans[0]){
            int flag = 1;
            for(int j=0;j<ans.length();j++){
                if(str[i+j]!=ans[j]){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                cnt++;
                i += ans.length()-1;
            }
        }
    }
    cout << cnt << "\n";
    
}