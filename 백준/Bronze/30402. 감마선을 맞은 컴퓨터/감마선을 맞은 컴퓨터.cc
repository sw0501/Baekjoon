#include<iostream>

using namespace std;

int main(){
    
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            char c;
            cin >> c;
            if(c=='w'){
                cout << "chunbae";
                return 0;
            }
            else if(c=='b'){
                cout << "nabi";
                return 0;
            }
            else if(c=='g'){
                cout << "yeongcheol";
                return 0;
            }
        }
    }
    
    return 0;
}