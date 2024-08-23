#include<iostream>

using namespace std;

int main(){
    
    int stair = 17;
    int es = 20;
    
    int total = 0;
    for(int i=0;i<4;i++){
        string str;
        int num;
        cin >> str >> num;
        
        if(str=="Es"){
            total += num*21;            
        }
        else{
            total += num*17;
        }
    }
    cout << total << "\n";
    
    return 0;
}