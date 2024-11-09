#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int N;
    cin >> N;
    
    int arr[6] = {0,};
    
    for(int i=0;i<6;i++){
        cin >> arr[i];
    }
    
    int T,P;
    cin >> T >> P;
    
    int t = 0;
    int p1 = 0;
    int p2 = 0;
    for(int i=0;i<6;i++){
        t += arr[i] / T + (arr[i] % T ? 1 : 0);
    }
    
    p1 += N / P;
    p2 = N%P;
    
    cout << t << "\n";
    cout << p1 << " " << p2 << "\n";
    
    return 0;
}
