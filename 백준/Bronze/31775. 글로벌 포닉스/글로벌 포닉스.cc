#include<iostream>
using namespace std;

int main(){
    
    string s1,s2,s3;
    
    int num[26] = {0,};
    
    cin >> s1 >> s2 >> s3;
    
    if(!(s1[0]>='0' && s1[0]<='9')){
        num[s1[0]-'a']++;
    }
    if(!(s2[0]>='0' && s2[0]<='9')){
        num[s2[0]-'a']++;
    }
    if(!(s3[0]>='0' && s3[0]<='9')){
        num[s3[0]-'a']++;
    }
    
    if(num['l'-'a']==1 && num['k'-'a']==1 && num['p'-'a']==1){
        cout << "GLOBAL" << "\n";
    }
    else{
        cout << "PONIX" << "\n";
    }
    
    
    
    return 0;
}