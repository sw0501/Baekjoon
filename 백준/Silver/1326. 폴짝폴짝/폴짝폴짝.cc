#include<iostream>
#include<queue>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int arr[10001] = {0,};
    int ck[10001] = {0,};
    
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    
    int a,b;
    cin >> a >> b;
    
    queue<pair<int,int>>br;
    
    br.push({a,0});
    ck[a] = 1;
    
    int ans = -1;
    
    while(!br.empty()){
        int idx = br.front().first;
        int cnt = br.front().second;
        
        if(idx == b){
            ans = cnt;
            break;
        }
        
        int add = 1;
        while(1){
            int num = idx + arr[idx] * add;
            if(num > N || num <= 0)break;
            if(!ck[num]){
                br.push({num,cnt+1});
                ck[num] = 1;
            }
            add++;
        }
        
        add = 1;
        while(1){
            int num = idx - arr[idx] * add;
            if(num > N || num <= 0)break;
            if(!ck[num]){
                br.push({num,cnt+1});
                ck[num] = 1;
            }
            add++;
        }
        
        br.pop();
        
    }
    
    cout << ans << "\n";
    
    return 0;
}