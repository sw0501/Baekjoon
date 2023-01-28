#include<iostream>

using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long M;
    cin >> M;
    
    long long x,y,z;
    for(long long i=0;i<M;i++){
        cin >> x >> y >> z;
        if(x>y-z){
            cout << "do not advertise\n";
        }
        else if(x==y-z){
            cout << "does not matter\n";
        }
        else{
            cout << "advertise\n";
        }
    }
    
    return 0;
}