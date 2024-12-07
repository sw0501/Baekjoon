#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int N;
    cin >> N;
    
    int cnt = 0;
    string name = "";
    int count = 0;
        
    for(int i=0;i<N;i++){
        string str;
        
        cin >> str;
        
        int K,M;
        cin >> K >> M;
        
        int temp = 0;
        while(K<=M){
            M -= K;
            M += 2;
            count++;
            temp++;
        }
        
        if(temp > cnt){
            name = str;
            cnt = temp;
        }
    }
    
    cout << count << "\n";
    cout << name << "\n";
    return 0;
}
