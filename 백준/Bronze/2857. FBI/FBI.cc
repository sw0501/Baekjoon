#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    
    int flag = 1;
    for(int i=1;i<=5;i++){
        string str;
        
        cin >> str;
        if(str.find("FBI")!=string::npos){
            cout << i << " ";
            flag = 0;
        }
    }
    if(flag){
        cout << "HE GOT AWAY!";
    }
    
    return 0;
}