#include<iostream>

using namespace std;

int main(){
    
    
    for(int i=0;i<3;i++){
        int cnt=0;
        int wood;
        for(int j=0;j<4;j++){
            cin >> wood;
            if(wood==0)cnt++;
        }
        if(cnt==0){
           cout << "E" << "\n"; 
        }
        else if(cnt==1){
           cout << "A" << "\n"; 
        }
        else if(cnt==2){
           cout << "B" << "\n"; 
        }
        else if(cnt==3){
           cout << "C" << "\n"; 
        }
        else if(cnt==4){
           cout << "D" << "\n"; 
        }
    }
    
    return 0;
}