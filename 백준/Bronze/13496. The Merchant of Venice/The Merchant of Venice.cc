#include<iostream>

using namespace std;

int main(){
    
    int K;
    cin >> K;
    
    for(int i=0;i<K;i++){
        int n,s,d;
        cin >> n >> s >> d;
        
        int x = 0;
        for(int j=0;j<n;j++){
            int dist,value;
            cin >> dist >> value;
            if(dist <= s*d){
                x += value;
            }
        }
        
        cout << "Data Set " << i + 1 << ":\n";
        cout << x << "\n";
        
        if(i!=K-1)cout << "\n";
    }
    
    return 0;
}