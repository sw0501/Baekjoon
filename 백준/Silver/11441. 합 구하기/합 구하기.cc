#include <iostream>

using namespace std;

int num[100001] = {0,};
int sum[100001] = {0,};
int main() 
{
    
    cin.tie(NULL);
    cout.tie(NULL);
    
    ios_base::sync_with_stdio(false);
    
    // 코드를 작성해주세요
    
    int N;
    cin >> N;
    
    for(int i=1;i<=N;i++){
        cin >> num[i];
        sum[i] = num[i] + sum[i-1];
    }
    
    int M;
    cin >> M;
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        
        cout << sum[b] - sum[a-1] << "\n";
    }
    
    return 0;
}
