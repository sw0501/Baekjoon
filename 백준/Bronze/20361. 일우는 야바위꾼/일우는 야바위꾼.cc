#include <iostream>

using namespace std;

int arr[200001] = {0,};

int main() 
{
    // 코드를 작성해주세요
    
    
    int N,X,K;
    cin >> N >> X >> K;
    
    for(int i=0;i<K;i++){
        int a,b;
        cin >> a >> b;
        
        if(a == X){
            X = b;
        }
        else if(b == X){
            X = a;
        }
    }
    
    cout << X << "\n";
    
    
    return 0;
}
