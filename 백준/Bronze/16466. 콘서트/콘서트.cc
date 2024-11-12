#include <iostream>

using namespace std;

int ticket[1000001]  ={0,};

int main() 
{
    // 코드를 작성해주세요
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        ticket[num]=1;
    }
    
    for(int i=1;i<=1000000;i++){
        if(!ticket[i])
        {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}
