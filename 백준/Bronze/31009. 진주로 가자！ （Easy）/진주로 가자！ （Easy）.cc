#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    int N;
    cin >> N;
    
    int idx;
    
    int arr[1001] = {0,};
    int wage;
    for(int i=0;i<N;i++){
        string str;
        int num;
        cin >> str >> num;
        
        arr[i] = num;
        
        if(str == "jinju"){
            wage = num;
        }
    }
    
    int cnt= 0;
    
    for(int i=0;i<N;i++){
        if(arr[i] > wage)cnt++;
    }
    
    cout << wage << "\n";
    cout << cnt << "\n";
    return 0;
}
