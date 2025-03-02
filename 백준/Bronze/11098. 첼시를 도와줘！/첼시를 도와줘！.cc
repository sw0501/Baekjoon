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
        
        int price = 0;
        string name = "";
        for(int i=0;i<N;i++){
            int c;
            string str;
            
            cin >> c >> str;
            
            if( c > price){
                price  =c;
                name = str;
            }
        }
        cout << name << "\n";
    }
    return 0;
}
