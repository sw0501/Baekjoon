#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int T;
    cin >> T;
    
    for(int i=0;i<T;i++){
        int a,b,c;
        cin >> a >> b >> c;
        
        cout << "Data set: " << a << " " << b << " " << c << "\n";
        
        while(c>0){
            if(a>b){
                a/=2;
            }
            else{
                b/=2;
            }
            c--;
        }
        
        if(a>b){
        cout << a << " " << b << "\n";            
        }
        else{
                    cout << b << " " << a << "\n";
        }

        if(i!=T-1)cout << "\n";
    }
    return 0;
}
