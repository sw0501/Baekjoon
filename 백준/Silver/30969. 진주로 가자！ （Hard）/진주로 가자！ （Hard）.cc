#include<iostream>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int arr[1002] = {0,};
    
    int N;
    cin >> N;
    
    string str;
    long long int num;
    
    int cost = 0;
    for(int i=0;i<N;i++){
        cin >> str;
        cin >> num;
        
        if(str=="jinju")cost = num;
        
        if(num<=1000){
            arr[num]++;
        }
        else{
            arr[1001]++;
        }
    }
    
    
    int ans = 0;
    
    for(int i=cost+1;i<=1001;i++){
        ans += arr[i];
    }
    
    cout << cost << "\n" << ans << "\n";
    
    return 0;
}