#include<iostream>

using namespace std;

int main(){
    string S1,S2;
    getline(cin,S1);
    getline(cin,S2);
    

    
    int h1=-1,m1=-1,s1=-1;
    int h2=-1,m2=-1,s2=-1;
    
    
    int num = 0;
    for(int i=0;i<=S1.length();i++){
        if(S1[i] == ':' || S1[i] == '\0'){
            if(h1==-1){
                h1 = num;
            }
            else if(m1==-1){
                m1 = num;
            }
            else{
                s1 = num;
            }
            num = 0;
        }
        else if(S1[i]>='0' && S1[i]<='9'){
            num*=10;
            num += (int)(S1[i]-'0');
        }
    }
    
    num = 0;
    for(int i=0;i<=S2.length();i++){
        if(S2[i] == ':' || S2[i] == '\0'){
            if(h2==-1){
                h2 = num;
            }
            else if(m2==-1){
                m2 = num;
            }
            else{
                s2 = num;
            }
            num = 0;
        }
        else if(S2[i]>='0' && S2[i]<='9'){
            num*=10;
            num += (int)(S2[i]-'0');
        }
    }
    
    int ans = 0;
    
    if(s2 < s1){
        m2--;
        s2+=60;
        
    }
    ans += s2-s1;
    
    if(m2 < m1){
        h2--;
        m2+=60;
        
    }
    ans += (m2-m1)*60;
    
    if(h2 < h1){
        h2+=24;
    }
    ans += (h2-h1)*3600;
    
    cout << ans << "\n";
    
    return 0;
}