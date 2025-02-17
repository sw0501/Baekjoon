#include<iostream>

using namespace std;

int main(){
    
    int l = 0,t=0;
    
    for(int i=0;i<9;i++){
        string name;
        cin >> name;
        
        if(name=="Lion")l++;
        else{
         t++;
        }
    }
    
    if(l>t){
        cout << "Lion";
    }
    else cout << "Tiger";
    
    return 0;
}