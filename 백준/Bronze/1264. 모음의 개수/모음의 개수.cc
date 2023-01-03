#include<iostream>

using namespace std;

int main(){
    
    while(1){
        int C=0;
        string str;
        getline(cin,str);
        if(str=="#"){
            break;
        }
        else{
            for(int i=0;i<str.length();i++){
                if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'){
                    C++;
                }
            }
        }
        cout << C << "\n";
    }
    
    
    
    return 0;
}