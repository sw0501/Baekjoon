#include<iostream>

using namespace std;

int menu[11] = {0,};
int main(){
    
    int N;
    cin >> N;
    
    for(int i=1;i<=N;i++){
        cin >> menu[i];
    }

    int M;
    cin >> M;
    
    int ans = 0;
    for(int i=0;i<M;i++){
        int num;
        cin >> num;
        ans += menu[num];
    }
    
    cout << ans << "\n";
    
    return 0;
}