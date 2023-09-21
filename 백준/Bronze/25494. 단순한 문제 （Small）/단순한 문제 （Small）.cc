#include<iostream>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    for(int t=0;t<T;t++){
        int a,b,c;
        cin >> a >> b >> c;
        int n = 0;
        
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                for(int k=1;k<=c;k++){
                    if(i%j == j%k && j%k == k%i){
                        n++;
                    }
                }
            }
        }
        cout << n << "\n";
    }
    
    
    
    
    return 0;
}