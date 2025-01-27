#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int T;
    cin >> T;
    
    for(int t=0;t<T;t++){
        int N;
        cin >> N;
        
        int v = 0;
        int flag = 0;
        
        cout << "Denominations: ";
        for(int i =0;i<N;i++){
            int n;
            cin >> n;
            cout << n;
            if(i!=N-1)cout << " ";
            
            if(v*2>n){
                flag = 1;
            }
            v = n;
        }
        cout << "\n";
        if(flag){
            cout << "Bad coin denominations!\n";
        }
        else{
            cout << "Good coin denominations!\n";
        }
        if(t!=T-1)cout << "\n";
    }
    return 0;
}
