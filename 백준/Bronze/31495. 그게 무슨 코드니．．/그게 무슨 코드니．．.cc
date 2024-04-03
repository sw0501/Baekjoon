#include<iostream>

using namespace std;

int main(){
    
    string str;
    getline(cin,str);
    
    if(str[0]=='\"' && str[str.length()-1]=='\"'){
        if(str.length()>2){
            for(int j=1;j<str.length()-1;j++){
                cout << str[j];
            }
            
        }
        else{
                cout << "CE";
            }
    }
    else{
                cout << "CE";
            }
    
    
    return 0;
}