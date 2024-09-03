#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    
    for(int i=0;i<N;i++){
        int a = 0,b = 0;
        for(int j=0;j<10;j++){
            int num;
            cin >> num;
            if(num==17)a=1;
            else if(num==18)b=1;
            
            cout << num << " ";
        }
        cout << "\n";
        if(a==1 && b==1){
            cout << "both" << "\n";
        }
        else if(a==1){
            cout << "zack" << "\n";
        }
        else if(b==1){
            cout << "mack" << "\n";
        }
        else{
            cout << "none" << "\n";
        }
        cout << "\n";
    }
    
    return 0;
}