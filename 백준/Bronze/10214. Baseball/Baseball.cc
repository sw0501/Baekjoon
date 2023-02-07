#include<iostream>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    for(int t=0;t<T;t++){
        int pa=0,pb=0;
        int a,b;
        for(int i=0;i<9;i++){
            cin >> a >> b;
            pa += a;
            pb += b;
        }
        if(pa>pb){
            cout << "Yonsei" << "\n";
        }
        else if(pa==pb){
            cout << "Draw"<<"\n";
        }
        else {
            cout << "Korea" << "\n";
        }
    }
    
    
    return 0;
}