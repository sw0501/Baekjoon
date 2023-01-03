#include<iostream>
#include<utility>
#include<queue>
#include<algorithm>

using namespace std;


int main(){
    
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int N,pos;
        int pri[100];
        cin >> N >> pos;
        queue<pair<int,int>>Q;
        for(int j=0;j<N;j++){
            int temp=0;
            cin >> temp;
            pri[j]=temp;
            Q.push(make_pair(temp,j));
        }
        sort(pri,pri+N);
        reverse(pri,pri+N);
        
        int c=0;
        while(!Q.empty()){
            int num=Q.front().first;
            int idx=Q.front().second;
            Q.pop();
            if(num>=pri[c]){
                c++;
                if(idx==pos)cout << c << "\n";
            }
            else{
                Q.push(make_pair(num,idx));
            }
        }
    }
    
    
    
    return 0;
}